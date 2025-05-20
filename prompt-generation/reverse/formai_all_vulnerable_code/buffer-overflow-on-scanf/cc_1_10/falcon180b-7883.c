//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using a Caesar cipher
void caesar_encrypt(char* message, int key) {
    int length = strlen(message);
    char* result = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);

        if (c >= 'A' && c <= 'Z') {
            result[i] = (c - 'A' + key) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            result[i] = (c - 'a' + key) % 26 + 'a';
        } else {
            result[i] = c;
        }
    }

    result[length] = '\0';
    printf("Encrypted message: %s\n", result);
}

// Function to decrypt a message using a Caesar cipher
void caesar_decrypt(char* message, int key) {
    int length = strlen(message);
    char* result = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);

        if (c >= 'A' && c <= 'Z') {
            result[i] = (c - 'A' - key + 26) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            result[i] = (c - 'a' - key + 26) % 26 + 'a';
        } else {
            result[i] = c;
        }
    }

    result[length] = '\0';
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    caesar_encrypt(message, key);
    caesar_decrypt(message, key);

    return 0;
}