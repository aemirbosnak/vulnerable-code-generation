//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char* fileName, char* key) {
    // Open the file in read mode
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Open the file in write mode
    char* encryptedName = malloc(strlen(fileName) + strlen(key) + 5);
    strcpy(encryptedName, fileName);
    strcat(encryptedName, ".enc");
    FILE* fpEnc = fopen(encryptedName, "w");
    if (fpEnc == NULL) {
        free(encryptedName);
        printf("Error opening encrypted file\n");
        return;
    }

    // Read the file line by line
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Encrypt the line using the key
        char encryptedLine[100];
        for (int i = 0; i < strlen(line); i++) {
            encryptedLine[i] = line[i] ^ key[i % strlen(key)];
        }

        // Write the encrypted line to the encrypted file
        fputs(encryptedLine, fpEnc);
    }

    // Close the files
    fclose(fp);
    fclose(fpEnc);
    free(encryptedName);
}

// Function to decrypt a file
void decryptFile(char* fileName, char* key) {
    // Open the file in read mode
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Open the file in write mode
    char* decryptedName = malloc(strlen(fileName) + strlen(key) + 5);
    strcpy(decryptedName, fileName);
    strcat(decryptedName, ".dec");
    FILE* fpDec = fopen(decryptedName, "w");
    if (fpDec == NULL) {
        free(decryptedName);
        printf("Error opening decrypted file\n");
        return;
    }

    // Read the file line by line
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Decrypt the line using the key
        char decryptedLine[100];
        for (int i = 0; i < strlen(line); i++) {
            decryptedLine[i] = line[i] ^ key[i % strlen(key)];
        }

        // Write the decrypted line to the decrypted file
        fputs(decryptedLine, fpDec);
    }

    // Close the files
    fclose(fp);
    fclose(fpDec);
    free(decryptedName);
}

int main() {
    // Prompt user for input
    char fileName[100];
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", fileName);
    printf("Enter the encryption key: ");
    char key[100];
    scanf("%s", key);

    // Encrypt the file
    encryptFile(fileName, key);

    // Prompt user for input
    printf("Enter the name of the file to decrypt: ");
    char decryptFileName[100];
    scanf("%s", decryptFileName);
    printf("Enter the decryption key: ");
    char decryptKey[100];
    scanf("%s", decryptKey);

    // Decrypt the file
    decryptFile(decryptFileName, decryptKey);

    return 0;
}