//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted[i] = (message[i] + key[i % SIZE]) % 26 + 'a';
        } else {
            encrypted[i] = message[i];
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted, char* key, char* decrypted) {
    for (int i = 0; encrypted[i]!= '\0'; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[i] = (encrypted[i] - key[i % SIZE] + 26) % 26 + 'a';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
}

int main() {
    char message[SIZE], encrypted[SIZE], decrypted[SIZE];
    char key[SIZE];

    // Generate a random key
    generate_key(key);

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key, encrypted);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message using the key
    decrypt(encrypted, key, decrypted);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}