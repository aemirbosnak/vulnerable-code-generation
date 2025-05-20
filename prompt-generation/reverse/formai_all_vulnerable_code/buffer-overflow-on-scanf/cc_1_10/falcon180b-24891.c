//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16 // Maximum length of the encryption key
#define MAX_MESSAGE_LENGTH 100 // Maximum length of the message

typedef struct {
    char key[MAX_KEY_LENGTH+1]; // Encryption key
    int shift; // Shift value for Caesar cipher
} encryption_t;

// Function to initialize the encryption key
void init_encryption_key(encryption_t* encryption, char* key) {
    strcpy(encryption->key, key);
    encryption->shift = 0; // Start with no shift
}

// Function to encrypt the message using Caesar cipher
void encrypt_message(encryption_t* encryption, char* message) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + encryption->shift);
            } else {
                message[i] = tolower(message[i] + encryption->shift);
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt_message(encryption_t* encryption, char* message) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] - encryption->shift);
            } else {
                message[i] = tolower(message[i] - encryption->shift);
            }
        }
        i++;
    }
}

int main() {
    encryption_t encryption;
    char message[MAX_MESSAGE_LENGTH+1];
    char key[MAX_KEY_LENGTH+1];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Get the encryption key from the user
    printf("Enter an encryption key: ");
    scanf("%s", key);

    // Initialize the encryption key
    init_encryption_key(&encryption, key);

    // Encrypt the message
    encrypt_message(&encryption, message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt_message(&encryption, message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}