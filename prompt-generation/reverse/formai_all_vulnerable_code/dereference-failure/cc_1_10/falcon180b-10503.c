//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey"
#define BLOCK_SIZE 16

// Function to encrypt the file
void encrypt(FILE *inputFile, FILE *outputFile) {
    char buffer[BLOCK_SIZE];
    char encryptedBuffer[BLOCK_SIZE + 1];
    int i, j;

    while (fread(buffer, sizeof(char), BLOCK_SIZE, inputFile)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            encryptedBuffer[i] = buffer[i] ^ KEY[i % strlen(KEY)];
        }
        encryptedBuffer[BLOCK_SIZE] = '\0';
        fwrite(encryptedBuffer, sizeof(char), BLOCK_SIZE + 1, outputFile);
    }
}

// Function to decrypt the file
void decrypt(FILE *inputFile, FILE *outputFile) {
    char buffer[BLOCK_SIZE];
    char decryptedBuffer[BLOCK_SIZE + 1];
    int i, j;

    while (fread(buffer, sizeof(char), BLOCK_SIZE, inputFile)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            decryptedBuffer[i] = buffer[i] ^ KEY[i % strlen(KEY)];
        }
        decryptedBuffer[BLOCK_SIZE] = '\0';
        fwrite(decryptedBuffer, sizeof(char), BLOCK_SIZE + 1, outputFile);
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char mode;

    if (argc!= 4) {
        printf("Usage: %s [e/d] input_file output_file\n", argv[0]);
        exit(1);
    }

    mode = argv[1][0];
    inputFile = fopen(argv[2], "rb");
    outputFile = fopen(argv[3], "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    if (mode == 'e') {
        encrypt(inputFile, outputFile);
        printf("File encrypted successfully.\n");
    } else if (mode == 'd') {
        decrypt(inputFile, outputFile);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode.\n");
        exit(1);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}