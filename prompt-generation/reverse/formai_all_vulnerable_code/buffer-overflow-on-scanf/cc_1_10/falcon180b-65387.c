//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 26

// Function to generate a random string of length n
void generateRandomString(char *str, int n) {
    int i;
    for (i = 0; i < n; i++) {
        str[i] = rand() % N + 'a';
    }
    str[n] = '\0';
}

// Function to encrypt a message using a key
void encrypt(char *message, char *key, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key[j] - 'a') % N + 'a';
            j = (j + 1) % strlen(key);
        }
        ciphertext[i] = ch;
    }
    ciphertext[i] = '\0';
}

// Function to decrypt a message using a key
void decrypt(char *ciphertext, char *key, char *message) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key[j] + 'a') % N + 'a';
            j = (j + 1) % strlen(key);
        }
        message[i] = ch;
    }
    message[i] = '\0';
}

int main() {
    int i;
    char message[100], key[100], ciphertext[100];

    // Generate a random key
    generateRandomString(key, 10);

    // Prompt user to enter a message
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key, ciphertext);

    // Print the encrypted message
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the encrypted message using the key
    decrypt(ciphertext, key, message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}