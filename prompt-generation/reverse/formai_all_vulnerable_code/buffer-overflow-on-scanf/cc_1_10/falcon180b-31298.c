//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key;
            if (message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        }
        i++;
    }
}

// Function to generate a random key
int generate_key() {
    int key = rand() % 26;
    return key;
}

int main() {
    char message[1000];
    int key;

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    key = generate_key();

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}