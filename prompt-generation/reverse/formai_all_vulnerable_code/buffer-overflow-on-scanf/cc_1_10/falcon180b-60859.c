//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 16

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[MAX_LENGTH];
    encrypted_message[0] = '\0';

    // Iterate through each character in the message
    for (i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Get the ASCII value of the letter
            int ascii_value = c - 97;

            // Encrypt the letter using the key
            int encrypted_ascii_value = ((ascii_value + (int)key[i % KEY_LENGTH]) % 26) + 97;

            // Append the encrypted letter to the encrypted message
            strcat(encrypted_message, (char)encrypted_ascii_value);
        } else {
            // Append non-letter characters to the encrypted message as is
            strcat(encrypted_message, message[i]);
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* encrypted_message, char* key) {
    int i, j;
    char decrypted_message[MAX_LENGTH];
    decrypted_message[0] = '\0';

    // Iterate through each character in the encrypted message
    for (i = 0; i < strlen(encrypted_message); i++) {
        char c = encrypted_message[i];

        // Check if the character is a letter
        if (isalpha(c)) {
            // Get the ASCII value of the letter
            int ascii_value = c - 97;

            // Decrypt the letter using the key
            int decrypted_ascii_value = ((ascii_value - (int)key[i % KEY_LENGTH] + 26) % 26) + 97;

            // Append the decrypted letter to the decrypted message
            strcat(decrypted_message, (char)decrypted_ascii_value);
        } else {
            // Append non-letter characters to the decrypted message as is
            strcat(decrypted_message, c);
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];

    // Get the message and key from the user
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}