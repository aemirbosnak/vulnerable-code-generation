//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to encrypt the message using recursion
void encrypt(char message[], char key[], int key_size) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[j];
            j++;
            if (j == key_size) {
                j = 0;
            }
        }
    }
}

// Function to decrypt the message using recursion
void decrypt(char message[], char key[], int key_size) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[j];
            j++;
            if (j == key_size) {
                j = 0;
            }
        }
    }
}

int main() {
    char message[MAX_SIZE], key[MAX_SIZE];
    int key_size;

    // Get the message and key from user input
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter key size (1-25): ");
    scanf("%d", &key_size);

    // Encrypt the message using recursion
    encrypt(message, key, key_size);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using recursion
    decrypt(message, key, key_size);
    printf("Decrypted message: %s\n", message);

    return 0;
}