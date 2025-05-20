//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY "secretkey"
#define BLOCK_SIZE 8
#define MAX_SIZE 100

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0, j = 0;
    char output[MAX_SIZE];
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                output[j++] = (char) (((int) message[i] - 65 + key) % 26 + 65);
            } else {
                output[j++] = (char) (((int) message[i] - 97 + key) % 26 + 97);
            }
        } else {
            output[j++] = message[i];
        }
        i++;
    }
    output[j] = '\0';
    printf("Encrypted message: %s\n", output);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0, j = 0;
    char output[MAX_SIZE];
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                output[j++] = (char) (((int) message[i] - 65 - key + 26) % 26 + 65);
            } else {
                output[j++] = (char) (((int) message[i] - 97 - key + 26) % 26 + 97);
            }
        } else {
            output[j++] = message[i];
        }
        i++;
    }
    output[j] = '\0';
    printf("Decrypted message: %s\n", output);
}

int main() {
    char message[MAX_SIZE];
    int key, choice;

    // Get the message from user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Get the encryption/decryption key from user
    printf("Enter the encryption/decryption key (1 for encryption, 2 for decryption): ");
    scanf("%d", &choice);

    // Get the encryption/decryption key from user
    printf("Enter the encryption/decryption key: ");
    scanf("%s", KEY);

    // Encrypt the message
    encrypt(message, choice * 3);

    // Decrypt the message
    decrypt(message, choice * 3);

    return 0;
}