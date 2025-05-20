//FormAI DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define BUFFER_SIZE 1024

void encryptFile(char *fileName, char *key) {
    FILE *inputFile, *outputFile;
    char outputFileName[MAX_FILE_NAME];
    char buffer[BUFFER_SIZE];
    int keyIndex = 0, bytesRead;

    /* Open input file for reading */
    inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file '%s'\n", fileName);
        return;
    }

    /* Create output file for writing */
    strcpy(outputFileName, fileName);
    strcat(outputFileName, ".enc");
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error creating output file '%s'\n", outputFileName);
        return;
    }

    /* Encrypt the file */
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ key[keyIndex];
            keyIndex++;
            if (keyIndex == strlen(key)) {
                keyIndex = 0;
            }
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    /* Close files */
    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully. Output file: '%s'\n", outputFileName);
}

int main() {
    char fileName[MAX_FILE_NAME], key[100];

    /* Get the file name and encryption key from user */
    printf("Enter the name of the file to encrypt: ");
    fgets(fileName, MAX_FILE_NAME, stdin);
    fileName[strlen(fileName) - 1] = '\0';

    printf("Enter the encryption key: ");
    scanf("%s", key);

    /* Encrypt the file */
    printf("Encrypting file...\n");
    encryptFile(fileName, key);

    return 0;
}