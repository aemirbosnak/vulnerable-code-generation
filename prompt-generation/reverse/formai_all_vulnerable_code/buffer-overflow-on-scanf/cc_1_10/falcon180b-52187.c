//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 16

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[strlen(message)];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (char) (((int) message[i] + (int) key[i % KEY_LENGTH]) % 26 + 'a');
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key) {
    int i, j;
    char decrypted_message[strlen(encrypted_message)];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = (char) (((int) encrypted_message[i] - (int) key[i % KEY_LENGTH]) % 26 + 'a');
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[KEY_LENGTH + 1];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the message using the key
    decrypt(message, key);

    return 0;
}