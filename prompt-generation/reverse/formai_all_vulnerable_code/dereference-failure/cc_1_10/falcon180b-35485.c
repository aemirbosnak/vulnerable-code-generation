//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt the input file
void encryptFile(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    char buffer[1024];
    int bufferSize = 0;

    while ((bufferSize = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < bufferSize; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }

        fwrite(buffer, 1, bufferSize, output);
    }

    fclose(input);
    fclose(output);
}

// Function to decrypt the input file
void decryptFile(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    char buffer[1024];
    int bufferSize = 0;

    while ((bufferSize = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < bufferSize; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }

        fwrite(buffer, 1, bufferSize, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <encrypt|decrypt>\n", argv[0]);
        return 1;
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];
    char* operation = argv[3];

    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Invalid operation. Please use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}