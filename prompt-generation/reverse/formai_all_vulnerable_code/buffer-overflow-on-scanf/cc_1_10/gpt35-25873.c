//FormAI DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the file
void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    FILE* fptr1 = fopen(inputFile, "r");
    FILE* fptr2 = fopen(outputFile, "w");
    int keyLength = strlen(key);
    int i = 0;
    char ch;

    while ((ch = fgetc(fptr1)) != EOF) {
        ch ^= key[i++ % keyLength];
        fputc(ch, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);
}

// Function to decrypt the file
void decryptFile(const char* inputFile, const char* outputFile, const char* key) {
    FILE* fptr1 = fopen(inputFile, "r");
    FILE* fptr2 = fopen(outputFile, "w");
    int keyLength = strlen(key);
    int i = 0;
    char ch;

    while ((ch = fgetc(fptr1)) != EOF) {
        ch ^= key[i++ % keyLength];
        fputc(ch, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);
}

// Main function
int main() {
    char key[100];
    char inputFile[100];
    char outputFile[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    encryptFile(inputFile, "encrypted_file.txt", key);
    decryptFile("encrypted_file.txt", outputFile, key);

    printf("File encrypted and decrypted successfully.\n");

    return 0;
}