//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char message[], char key[]) {
    int i, j;
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Repeat the key until it is equal to the message length
    while (key_length < message_length) {
        strcat(key, key);
        key_length += strlen(key);
    }

    // Encrypt the message
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = key[(int) message[i] - 65];
            } else {
                message[i] = key[(int) message[i] - 97];
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], char key[]) {
    int i, j;
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Repeat the key until it is equal to the message length
    while (key_length < message_length) {
        strcat(key, key);
        key_length += strlen(key);
    }

    // Decrypt the message
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (char) ((int) message[i] - (int) key[i % key_length] + 65);
            } else {
                message[i] = (char) ((int) message[i] - (int) key[i % key_length] + 97);
            }
        }
    }
}

// Function to generate a random key
void generate_key(char key[]) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

int main() {
    char message[1000];
    char key[100];

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}