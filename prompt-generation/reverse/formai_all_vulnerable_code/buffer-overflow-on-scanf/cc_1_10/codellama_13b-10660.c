//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: rigorous
/*
 * C Encryption Example Program
 *
 * This program uses a simple Caesar cipher to encrypt and decrypt a message.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256

// Function to encrypt a message using a Caesar cipher
void encrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] - 'A') + shift) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] - 'a') + shift) % 26) + 'a';
        }
    }
}

// Function to decrypt a message using a Caesar cipher
void decrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] - 'A') - shift + 26) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] - 'a') - shift + 26) % 26) + 'a';
        }
    }
}

int main() {
    char message[MAX_MSG_LEN];
    int shift;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MSG_LEN, stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}