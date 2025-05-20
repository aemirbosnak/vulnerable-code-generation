//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a key
void generate_key(char *key) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[SIZE] = '\0';
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j;
    char encrypted[SIZE];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[j++] = (char) (((int) message[i] + (int) key[i % SIZE]) % 26 + 'A');
            } else {
                encrypted[j++] = (char) (((int) message[i] + (int) key[i % SIZE]) % 26 + 'a');
            }
        } else {
            encrypted[j++] = message[i];
        }
    }
    encrypted[j] = '\0';
    strcpy(message, encrypted);
}

// Function to decrypt a message
void decrypt(char *message, char *key) {
    int i, j;
    char decrypted[SIZE];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted[j++] = (char) (((int) message[i] - (int) key[i % SIZE] + 26) % 26 + 'A');
            } else {
                decrypted[j++] = (char) (((int) message[i] - (int) key[i % SIZE] + 26) % 26 + 'a');
            }
        } else {
            decrypted[j++] = message[i];
        }
    }
    decrypted[j] = '\0';
    strcpy(message, decrypted);
}

int main() {
    char message[SIZE];
    char key[SIZE];

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate key
    generate_key(key);

    // Encrypt message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}