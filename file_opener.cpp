#include <bits/stdc++.h>
#include "scanner.h"
#include "semantics.h"
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "No file provided." << endl;
        return 1;
    }

    char* fileOpen = argv[1];
    FILE *filePointer = fopen(fileOpen, "r");
    if (filePointer == NULL) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    fseek(filePointer, 0, SEEK_END);    
    int fileSize = ftell(filePointer);
    fseek(filePointer, 0, SEEK_SET);

    char* buffer = new(nothrow) char[fileSize + 1];
    if (!buffer) {
        cerr << "Allocation failed" << endl;
        fclose(filePointer);
        return 1;
    }

    fread(buffer, sizeof(char), fileSize, filePointer);
    buffer[fileSize] = '\0';

    // Perform analysis
    scanner(buffer);         // Writes to tokens.txt
    // parse(0);                
    
    delete[] buffer;
    fclose(filePointer);
    return 0;
}
