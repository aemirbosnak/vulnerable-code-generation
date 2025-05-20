//Falcon-180B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char key[], int key_length) {
    for (int i = 0; i < key_length; i++) {
        char random_char = rand() % 26 + 'A';
        key[i] = random_char;
    }
    key[key_length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char message[], char key[], char encrypted_message[]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] + key[i % strlen(key)]) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char encrypted_message[], char key[], char decrypted_message[]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[i % strlen(key)]) % 26 + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    srand(time(NULL));

    // Get the message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Get the key length from the user
    int key_length;
    printf("Enter the key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &key_length);

    // Generate the key
    char key[MAX_KEY_LENGTH];
    generate_key(key, key_length);

    // Encrypt the message
    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}