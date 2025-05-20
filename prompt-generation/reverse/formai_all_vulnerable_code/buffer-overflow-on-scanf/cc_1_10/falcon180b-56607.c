//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] + key[i % strlen(key)]) % 26 + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_length] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[i % strlen(key)]) % 26 + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[encrypted_message_length] = '\0';
}

int main() {
    // Generate a random key
    char key[10] = "";
    generate_key(key, 10);

    // Get the message from the user
    char message[100] = "";
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    char encrypted_message[100] = "";
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char decrypted_message[100] = "";
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}