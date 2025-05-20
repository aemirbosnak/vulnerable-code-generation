//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt plaintext using Caesar cipher
void encrypt(char *message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + key) % 26;
            }
            else {
                message[i] = 'a' + (message[i] - 'a' + key) % 26;
            }
        }
    }
}

// Function to decrypt ciphertext using Caesar cipher
void decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    for(int i = 0; i < len; i++) {
        if(isalpha(ciphertext[i])) {
            if(isupper(ciphertext[i])) {
                ciphertext[i] = 'A' + (ciphertext[i] - 'A' - key + 26) % 26;
            }
            else {
                ciphertext[i] = 'a' + (ciphertext[i] - 'a' - key + 26) % 26;
            }
        }
    }
}

// Function to encrypt and decrypt using Caesar cipher
void caesar(char *message, int key) {
    encrypt(message, key);
    decrypt(message, key);
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    int key;
    printf("Enter the key (1-25): ");
    scanf("%d", &key);
    caesar(message, key);
    printf("Encrypted message: %s\n", message);
    return 0;
}