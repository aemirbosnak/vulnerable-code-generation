//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_KEY_LENGTH 256

// function to encrypt and decrypt file
void encryptFile(char* fileName, char* key) {
    FILE* inputFile;
    FILE* outputFile;
    char outputFileName[MAX_FILE_NAME_LENGTH];
    char c;
    int i = 0;
    int keyLength = strlen(key);
    int keyIndex = 0;

    // open input file
    if((inputFile = fopen(fileName, "r")) == NULL) {
        printf("Error: Unable to open input file!");
        exit(1);
    }

    // create output file name
    strcpy(outputFileName, fileName);
    strcat(outputFileName, ".enc");

    // open output file
    if((outputFile = fopen(outputFileName, "w")) == NULL) {
        printf("Error: Unable to open output file!");
        exit(1);
    }

    // encrypt file
    c = fgetc(inputFile);
    while(c != EOF) {
        if(keyIndex == keyLength) {
            keyIndex = 0;
        }

        fputc((c ^ key[keyIndex]), outputFile);

        keyIndex++;
        c = fgetc(inputFile);
    }

    // close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete! Output file: %s\n", outputFileName);
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encryptFile(fileName, key);

    return 0;
}