//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num() {
    return rand() % 10000;
}

// Function to encrypt the message using the Caesar cipher
void caesar_encrypt(char* message, int key) {
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

// Function to decrypt the message using the Caesar cipher
void caesar_decrypt(char* message, int key) {
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
    return rand_num() % 26;
}

// Function to encrypt and decrypt the message
void encrypt_decrypt(char* message, int mode) {
    int key = generate_key();
    if (mode == 1) {
        caesar_encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else {
        caesar_decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
}

// Main function
int main() {
    char message[100];
    printf("Enter a message: ");
    scanf("%s", message);

    int choice;
    printf("1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);

    encrypt_decrypt(message, choice);

    return 0;
}