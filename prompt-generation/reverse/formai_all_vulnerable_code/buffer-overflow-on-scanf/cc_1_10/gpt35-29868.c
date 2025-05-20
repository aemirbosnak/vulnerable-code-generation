//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BUFFER_LENGTH 1000

void encrypt(FILE *inputFile, FILE *outputFile, char *key);
char *inputFileName();
char *outputFileName();
char *inputKey();

int main() {
    FILE *inputFile;
    FILE *outputFile;
    char *key = inputKey();
    char *input = inputFileName();
    char *output = outputFileName();

    inputFile = fopen(input, "rb");
    if(inputFile == NULL) {
        printf("Error: Input file could not be opened\n");
        exit(1);
    }

    outputFile = fopen(output, "wb");
    if(outputFile == NULL) {
        printf("Error: Output file could not be opened\n");
        exit(1);
    }

    encrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    free(input);
    free(output);
    free(key);

    return 0;
}

void encrypt(FILE *inputFile, FILE *outputFile, char *key) {
    char buffer[MAX_BUFFER_LENGTH];
    int keyLength = strlen(key);
    int i = 0;

    while(fread(buffer, sizeof(char), MAX_BUFFER_LENGTH, inputFile)) {
        for(i = 0; i < MAX_BUFFER_LENGTH; i++) {
            buffer[i] ^= key[(i % keyLength)];
        }
        fwrite(buffer, sizeof(char), MAX_BUFFER_LENGTH, outputFile);
    }

    int remainingBytes = ftell(inputFile) % MAX_BUFFER_LENGTH;
    if(remainingBytes > 0) {
        fread(buffer, sizeof(char), remainingBytes, inputFile);
        for(i = 0; i < remainingBytes; i++) {
            buffer[i] ^= key[(i % keyLength)];
        }
        fwrite(buffer, sizeof(char), remainingBytes, outputFile);
    }
}

char *inputFileName() {
    char *fileName = malloc(MAX_FILENAME_LENGTH);
    printf("Enter the name of the input file: ");
    scanf("%s", fileName);
    return fileName;
}

char *outputFileName() {
    char *fileName = malloc(MAX_FILENAME_LENGTH);
    printf("Enter the name of the output file: ");
    scanf("%s", fileName);
    return fileName;
}

char *inputKey() {
    char *key = malloc(MAX_FILENAME_LENGTH);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    return key;
}