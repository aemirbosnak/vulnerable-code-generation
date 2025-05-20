//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char encryptionKey[] = "YOUR_SECRET_KEY"; // Adjust this to your liking

void encryptFile(char *fileName) {
    FILE *inputFile = fopen(fileName, "rb");
    FILE *outputFile = fopen("encrypted.txt", "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf(":( File opening failed. Check file permissions!");
        exit(1);
    }

    // Determine the file size
    fseek(inputFile, 0L, SEEK_END);
    size_t fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate space for the ciphertext
    unsigned char *ciphertext = malloc(fileSize);

    // Read the original file into a buffer
    fread(ciphertext, 1, fileSize, inputFile);

    // Encrypt the data using a simple XOR encryption
    for (size_t i = 0; i < fileSize; i++) {
        ciphertext[i] ^= encryptionKey[i % strlen(encryptionKey)];
    }

    // Write the encrypted data to the output file
    fwrite(ciphertext, 1, fileSize, outputFile);

    // Clean up
    fclose(inputFile);
    fclose(outputFile);
    free(ciphertext);

    printf("O_O File encrypted successfully! Prepare for the unknown...");
}

int main() {
    char inputFileName[50];
    
    printf("Type the name of the file you want to encrypt (without extension): ");
    scanf("%s", inputFileName);

    encryptFile(inputFileName);

    printf("\n(͡° ͜ʖ ͡°) Encryption complete. Your data is now safe from prying eyes...");
    return 0;
}