//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt the message
void encrypt(char *message) {
    int i, j, len = strlen(message);
    char *key = KEY;
    char *result = malloc(len + 1);

    // Encrypt the message
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            result[j++] = message[i] + (int)key[i % strlen(key)];
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
}

// Function to decrypt the message
void decrypt(char *message) {
    int i, j, len = strlen(message);
    char *key = KEY;
    char *result = malloc(len + 1);

    // Decrypt the message
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            result[j++] = (char)((int)message[i] - (int)key[i % strlen(key)]);
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt(message);
    decrypt(message);

    return 0;
}