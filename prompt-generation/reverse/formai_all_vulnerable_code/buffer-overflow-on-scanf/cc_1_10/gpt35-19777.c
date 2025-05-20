//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declarations
void encrypt(char *str, int key);
void decrypt(char *str, int key);

// main function
int main() {
    char message[50];
    int key;

    // Get user input
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("\nEncrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

// function to encrypt a message
void encrypt(char *str, int key) {
    int i;

    for(i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' + key) % 26) + 'A';
        }
    }
}

// function to decrypt a message
void decrypt(char *str, int key) {
    int i;

    for(i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}