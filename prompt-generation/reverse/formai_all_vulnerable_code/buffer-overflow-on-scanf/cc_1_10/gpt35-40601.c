//FormAI DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encrypt(char *string, int key)
{
    int i;
    for (i = 0; string[i] != '\0'; i++) {
        string[i] = string[i] + key;
    }
}

void decrypt(char *string, int key)
{
    int i;
    for (i = 0; string[i] != '\0'; i++) {
        string[i] = string[i] - key;
    }
}

int main(void) {
    char message[100], message_copy[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Make a copy of the message to encrypt/decrypt later
    strcpy(message_copy, message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    // Verify that the original message is the same as the decrypted message
    if (strcmp(message_copy, message) == 0) {
        printf("Original message matches decrypted message.\n");
    } else {
        printf("Error: Original message does not match decrypted message.\n");
    }

    return 0;
}