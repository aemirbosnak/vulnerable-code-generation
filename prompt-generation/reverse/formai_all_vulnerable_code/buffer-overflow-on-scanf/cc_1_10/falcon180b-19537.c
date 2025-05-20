//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
void strtoupper(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to encrypt a string using a key
void encrypt(char* str, char* key) {
    int len = strlen(str);
    int keylen = strlen(key);
    char result[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            strtoupper(str + i);
            strtoupper(key + j);
            result[i] = str[i] ^ key[j];
            j++;
            if (j == keylen) {
                j = 0;
            }
        } else {
            result[i] = str[i];
        }
    }
    strcpy(str, result);
}

// Function to decrypt a string using a key
void decrypt(char* str, char* key) {
    int len = strlen(str);
    int keylen = strlen(key);
    char result[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            strtoupper(str + i);
            strtoupper(key + j);
            result[i] = str[i] ^ key[j];
            j++;
            if (j == keylen) {
                j = 0;
            }
        } else {
            result[i] = str[i];
        }
    }
    strcpy(str, result);
}

int main() {
    char message[1000];
    char key[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}