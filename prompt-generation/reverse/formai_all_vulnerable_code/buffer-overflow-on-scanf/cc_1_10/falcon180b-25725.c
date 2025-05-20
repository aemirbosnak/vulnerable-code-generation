//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
        i++;
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from user
    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Get the key from user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, atoi(key));

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, atoi(key));

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}