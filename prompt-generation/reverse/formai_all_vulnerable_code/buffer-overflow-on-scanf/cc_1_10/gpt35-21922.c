//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char* inputFilename, const char* outputFilename);

int main(void) {
    char inputFilename[256];
    char outputFilename[256];

    printf("Enter input filename: ");
    scanf("%s", inputFilename);

    printf("Enter output filename: ");
    scanf("%s", outputFilename);

    encryptFile(inputFilename, outputFilename);

    printf("File encryption completed.\n");

    return 0;
}

void encryptFile(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile;
    FILE* outputFile;

    char key[256];
    int keyLength;

    unsigned char inputBuffer[1024];
    unsigned char outputBuffer[1024];
    size_t bytesRead;

    printf("Enter encryption key: ");
    scanf("%255s", key);
    keyLength = strlen(key);

    inputFile = fopen(inputFilename, "rb");
    if(!inputFile) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFilename, "wb");
    if(!outputFile) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while((bytesRead = fread(inputBuffer, 1, sizeof(inputBuffer), inputFile)) > 0) {
        for(size_t i = 0; i < bytesRead; ++i) {
            outputBuffer[i] = inputBuffer[i] ^ key[i % keyLength];
        }
        fwrite(outputBuffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}