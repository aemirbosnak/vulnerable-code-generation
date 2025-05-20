//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(char *fileName, char *key) {
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen(fileName, "r");
    fp2 = fopen("encrypted.txt", "w");
    int keyIndex = 0;
    int keyLength = strlen(key);
    
    while ((ch = fgetc(fp1)) != EOF) {
        // Shift the character by the corresponding key value
        int encryptedChar = ch + (int)key[keyIndex];
        // When the key is exhausted, start from the first character
        if (keyIndex == keyLength) {
            keyIndex = 0;
        }
        // Write the encrypted character to the new file
        fputc(encryptedChar, fp2);
        keyIndex++;
    }
    printf("The file has been encrypted successfully.\n");
    fclose(fp1);
    fclose(fp2);
}

// Function to decrypt the file
void decryptFile(char *fileName, char *key) {
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen(fileName, "r");
    fp2 = fopen("decrypted.txt", "w");
    int keyIndex = 0;
    int keyLength = strlen(key);
    
    while ((ch = fgetc(fp1)) != EOF) {
        // Shift the character back by the corresponding key value
        int decryptedChar = ch - (int)key[keyIndex];
        // When the key is exhausted, start from the first character
        if (keyIndex == keyLength) {
            keyIndex = 0;
        }
        // Write the decrypted character to the new file
        fputc(decryptedChar, fp2);
        keyIndex++;
    }
    printf("The file has been decrypted successfully.\n");
    fclose(fp1);
    fclose(fp2);
}


int main() {
    printf("Welcome to the futuristic C File Encryptor program!\n\n");
    printf("Please choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    int option;
    scanf("%d", &option);
    char fileName[100];
    char key[100];
    switch(option) {
        case 1:
            printf("Enter the name of the file to encrypt (with extension): ");
            scanf("%s", fileName);
            printf("Enter the encryption key: ");
            scanf("%s", key);
            encryptFile(fileName, key);
            break;
        case 2:
            printf("Enter the name of the file to decrypt (with extension): ");
            scanf("%s", fileName);
            printf("Enter the decryption key: ");
            scanf("%s", key);
            decryptFile(fileName, key);
            break;
        default:
            printf("Invalid option selected, please try again.\n");
            return 0;
    }
    return 0;
}