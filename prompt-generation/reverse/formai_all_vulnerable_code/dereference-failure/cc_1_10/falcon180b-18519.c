//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void encrypt(char* message, char* key) {
    int i, j, k;
    char* cipher = (char*) malloc(MAX_SIZE);
    char* key_copy = (char*) malloc(MAX_SIZE);

    strcpy(key_copy, key);

    for(i = 0, j = 0; i < strlen(message); i++, j++) {
        if(j == strlen(key_copy)) {
            j = 0;
        }

        cipher[i] = message[i] ^ key_copy[j];
    }

    cipher[i] = '\0';

    printf("Encrypted message: %s\n", cipher);

    free(cipher);
    free(key_copy);
}

void decrypt(char* cipher, char* key) {
    int i, j, k;
    char* message = (char*) malloc(MAX_SIZE);
    char* key_copy = (char*) malloc(MAX_SIZE);

    strcpy(key_copy, key);

    for(i = 0, j = 0; i < strlen(cipher); i++, j++) {
        if(j == strlen(key_copy)) {
            j = 0;
        }

        message[i] = cipher[i] ^ key_copy[j];
    }

    message[i] = '\0';

    printf("Decrypted message: %s\n", message);

    free(message);
    free(key_copy);
}

int main() {
    char* message = "Hello, world!";
    char* key = "secret";

    printf("Original message: %s\n", message);

    encrypt(message, key);

    printf("\n");

    decrypt(message, key);

    return 0;
}