//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_STRING_LENGTH 256

// Function to generate a random string of length n
void generateRandomString(char* str, int n) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < n; i++) {
        str[i] = charset[rand() % strlen(charset)];
    }
    str[n] = '\0';
}

// Function to encrypt the given string using the given key
void encrypt(char* str, char* key) {
    int keyLength = strlen(key);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] + key[i % keyLength];
    }
}

// Function to decrypt the given string using the given key
void decrypt(char* str, char* key) {
    int keyLength = strlen(key);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] - key[i % keyLength];
    }
}

int main() {
    srand(time(NULL));

    // Generate a random string
    char* inputString = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    generateRandomString(inputString, MAX_STRING_LENGTH);

    // Generate a random key
    char* key = (char*) malloc(MAX_KEY_LENGTH * sizeof(char));
    generateRandomString(key, MAX_KEY_LENGTH);

    // Encrypt the input string using the key
    char* encryptedString = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(encryptedString, inputString);
    encrypt(encryptedString, key);

    // Decrypt the encrypted string using the key
    char* decryptedString = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(decryptedString, encryptedString);
    decrypt(decryptedString, key);

    // Print the results
    printf("Input string: %s\n", inputString);
    printf("Encrypted string: %s\n", encryptedString);
    printf("Decrypted string: %s\n", decryptedString);

    free(inputString);
    free(key);
    free(encryptedString);
    free(decryptedString);

    return 0;
}