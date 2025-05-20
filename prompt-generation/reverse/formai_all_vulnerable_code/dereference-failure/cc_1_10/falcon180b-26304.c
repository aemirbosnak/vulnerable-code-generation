//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

// Define the key
#define KEY "secretkey"

// Define the encryption function
char* encrypt(char* message) {
    int len = strlen(message);
    char* encrypted = (char*)malloc(len + 1);
    char* key = (char*)malloc(strlen(KEY) + 1);
    strcpy(key, KEY);

    // Encrypt the message
    for (int i = 0; i < len; i++) {
        char c = toupper(message[i]);
        int k = c - 65;
        k = (k + 3) % 26;
        encrypted[i] = (char)((k + 65) % 26 + 65);
    }

    free(key);
    return encrypted;
}

// Define the decryption function
char* decrypt(char* encrypted) {
    int len = strlen(encrypted);
    char* decrypted = (char*)malloc(len + 1);
    char* key = (char*)malloc(strlen(KEY) + 1);
    strcpy(key, KEY);

    // Decrypt the message
    for (int i = 0; i < len; i++) {
        char c = toupper(encrypted[i]);
        int k = c - 65;
        k = (k - 3 + 26) % 26;
        decrypted[i] = (char)((k + 65) % 26 + 65);
    }

    free(key);
    return decrypted;
}

int main() {
    char* message = "Hello, world!";
    char* encrypted = encrypt(message);
    printf("Encrypted message: %s\n", encrypted);
    char* decrypted = decrypt(encrypted);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}