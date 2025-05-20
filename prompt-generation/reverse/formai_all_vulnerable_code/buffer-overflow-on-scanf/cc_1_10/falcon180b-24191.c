//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

// Function to encrypt the message
void encrypt(char *message) {
    int i, j, n = strlen(message);
    char *key = KEY;
    char *result = malloc(n * 2 + 1);

    for (i = 0, j = 0; i < n; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = tolower(message[i]) + (key[j % strlen(key)] - 'a' + 26) % 26;
            } else {
                result[j] = toupper(message[i]) + (key[j % strlen(key)] - 'A' + 26) % 26;
            }
        } else {
            result[j] = message[i];
        }
    }

    result[j] = '\0';
    printf("Encrypted message: %s\n", result);
}

// Function to decrypt the message
void decrypt(char *message) {
    int i, j, n = strlen(message);
    char *key = KEY;
    char *result = malloc(n * 2 + 1);

    for (i = 0, j = 0; i < n; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j] = (message[i] - key[j % strlen(key)] - 'A' + 26) % 26 + 'A';
            } else {
                result[j] = (message[i] - key[j % strlen(key)] - 'a' + 26) % 26 + 'a';
            }
        } else {
            result[j] = message[i];
        }
    }

    result[j] = '\0';
    printf("Decrypted message: %s\n", result);
}

// Main function
int main() {
    char message[100];
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    encrypt(message);
    decrypt(message);

    return 0;
}