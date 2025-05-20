//FormAI DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(FILE *input, FILE *output, char *key) {
    char buffer[BUFFER_SIZE];
    int keyLength = strlen(key);
    int i, j = 0;

    while (1) {
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, input);

        if (bytesRead == 0) {
            break;
        }

        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[j];
            j = (j + 1) % keyLength;
        }

        fwrite(buffer, 1, bytesRead, output);
    }
}

void decrypt(FILE *input, FILE *output, char *key) {
    encrypt(input, output, key);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encryption_key>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char *encryptionKey = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFileName);
        return 1;
    }

    if (outputFile == NULL) {
        printf("Error opening output file: %s\n", outputFileName);
        return 1;
    }

    char mode;

    do {
        printf("Do you want to encrypt or decrypt? (e/d)\n");
        scanf("%c", &mode);
    } while (mode != 'e' && mode != 'd');

    if (mode == 'e') {
        encrypt(inputFile, outputFile, encryptionKey);
        printf("File successfully encrypted.\n");
    } else {
        decrypt(inputFile, outputFile, encryptionKey);
        printf("File successfully decrypted.\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}