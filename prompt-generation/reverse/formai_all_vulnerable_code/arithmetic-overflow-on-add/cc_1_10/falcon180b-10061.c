//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
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
    // Get the message from the user
    char message[100];
    printf("Enter the message: ");
    scanf("%s", message);

    // Get the key from the user
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message using Caesar cipher
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using Caesar cipher
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}