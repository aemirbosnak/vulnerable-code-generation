//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(char* inputFile, char* outputFile, char* key) {
    FILE* fInput = fopen(inputFile, "rb");
    FILE* fOutput = fopen(outputFile, "wb");
    int keyLen = strlen(key);
    int index = 0;
    int data = 0;

    // Loop through each character in the input file
    while ((data = fgetc(fInput)) != EOF) {
        // XOR the character with the corresponding character in the key
        fputc(data ^ key[index], fOutput);

        index++;
        if (index == keyLen) {
            index = 0;
        }
    }

    // Close the files
    fclose(fInput);
    fclose(fOutput);

    printf("File encrypted successfully!\n");
}

// Function to decrypt the file
void decryptFile(char* inputFile, char* outputFile, char* key) {
    encryptFile(inputFile, outputFile, key);
}

int main() {
    // Get input file name
    char inputFile[100];
    printf("Enter input file name: ");
    scanf("%s", inputFile);

    // Get output file name
    char outputFile[100];
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    // Get encryption key
    char key[100];
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Encrypt the file
    encryptFile(inputFile, outputFile, key);

    // Decrypt the file
    char decryptedFile[100];
    strcpy(decryptedFile, "decrypted_");
    strcat(decryptedFile, outputFile);

    decryptFile(outputFile, decryptedFile, key);

    return 0;
}