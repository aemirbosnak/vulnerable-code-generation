//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;
    char encrypted_message[MAX];
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = message[i] + key;
            if (encrypted_message[i] > 'z') {
                encrypted_message[i] = encrypted_message[i] - 26;
            } else if (encrypted_message[i] < 'a') {
                encrypted_message[i] = encrypted_message[i] + 26;
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
    strcpy(message, encrypted_message);
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;
    char decrypted_message[MAX];
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            decrypted_message[i] = message[i] - key;
            if (decrypted_message[i] < 'a') {
                decrypted_message[i] = decrypted_message[i] + 26;
            } else if (decrypted_message[i] > 'z') {
                decrypted_message[i] = decrypted_message[i] - 26;
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }
    decrypted_message[i] = '\0';
    strcpy(message, decrypted_message);
}

// Function to generate a random key
void generate_key(int key[]) {
    int i;
    for (i = 0; i < 26; i++) {
        key[i] = rand() % 26;
    }
}

int main() {
    char message[MAX];
    int key[26];
    int i, j;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key[0]);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key[0]);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}