//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_STRING_LENGTH 1024

// Function to generate a random key of specified length
void generateKey(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the given string using the specified key
void encrypt(char* string, char* key) {
    int stringLength = strlen(string);
    char encryptedString[MAX_STRING_LENGTH];
    encryptedString[0] = '\0';

    for (int i = 0; i < stringLength; i++) {
        if (isalpha(string[i])) {
            char encryptedChar = (char) ((int) string[i] + (int) key[i % strlen(key)] - 65 % 26 + 65);
            strcat(encryptedString, &encryptedChar);
        }
        else {
            strcat(encryptedString, &string[i]);
        }
    }

    printf("Encrypted string: %s\n", encryptedString);
}

// Function to decrypt the given string using the specified key
void decrypt(char* string, char* key) {
    int stringLength = strlen(string);
    char decryptedString[MAX_STRING_LENGTH];
    decryptedString[0] = '\0';

    for (int i = 0; i < stringLength; i++) {
        if (isalpha(string[i])) {
            char decryptedChar = (char) ((int) string[i] - (int) key[i % strlen(key)] - 65 % 26 + 65);
            strcat(decryptedString, &decryptedChar);
        }
        else {
            strcat(decryptedString, &string[i]);
        }
    }

    printf("Decrypted string: %s\n", decryptedString);
}

int main() {
    srand(time(NULL));

    char key[MAX_KEY_LENGTH];
    generateKey(key, strlen(key));

    char stringToEncrypt[MAX_STRING_LENGTH];
    printf("Enter the string to encrypt: ");
    scanf("%s", stringToEncrypt);

    encrypt(stringToEncrypt, key);

    char stringToDecrypt[MAX_STRING_LENGTH];
    printf("Enter the string to decrypt: ");
    scanf("%s", stringToDecrypt);

    decrypt(stringToDecrypt, key);

    return 0;
}