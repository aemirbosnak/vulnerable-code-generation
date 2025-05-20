//FormAI DATASET v1.0 Category: File Encyptor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_PASSPHRASE_LEN 256
#define BLOCK_SIZE 16

void encrypt(FILE *inFile, FILE *outFile, unsigned char *key) {
    unsigned char block[BLOCK_SIZE];
    int bytesRead = 0, i;
    while ((bytesRead = fread(block, 1, BLOCK_SIZE, inFile)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            block[i] ^= key[i % strlen(key)];
        }
        fwrite(block, 1, bytesRead, outFile);
    }
}

void decrypt(FILE *inFile, FILE *outFile, unsigned char *key) {
    unsigned char block[BLOCK_SIZE];
    int bytesRead = 0, i;
    while ((bytesRead = fread(block, 1, BLOCK_SIZE, inFile)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            block[i] ^= key[i % strlen(key)];
        }
        fwrite(block, 1, bytesRead, outFile);
    }
}

int main() {
    char inFile[MAX_FILENAME_LEN], outFile[MAX_FILENAME_LEN], pass[MAX_PASSPHRASE_LEN];
    printf("Enter the name of the input file: ");
    scanf("%s", inFile);
    printf("Enter the name of the output file: ");
    scanf("%s", outFile);
    printf("Enter the passphrase: ");
    scanf("%s", pass);

    // Open input file
    FILE *inFilePtr = fopen(inFile, "rb");
    if (inFilePtr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    FILE *outFilePtr = fopen(outFile, "wb");
    if (outFilePtr == NULL) {
        printf("Error creating output file.\n");
        fclose(inFilePtr);
        return 1;
    }

    // Encrypt or decrypt file
    char choice;
    printf("Encrypt or decrypt? (e/d): ");
    scanf(" %c", &choice);
    if (choice == 'e') {
        encrypt(inFilePtr, outFilePtr, pass);
        printf("File encrypted successfully!\n");
    } else if (choice == 'd') {
        decrypt(inFilePtr, outFilePtr, pass);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid option selected.\n");
        fclose(inFilePtr);
        fclose(outFilePtr);
        return 1;
    }

    // Close files
    fclose(inFilePtr);
    fclose(outFilePtr);

    return 0;
}