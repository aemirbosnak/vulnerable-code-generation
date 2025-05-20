//Falcon-180B DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define KEY_SIZE 16

// Function to encrypt the given message using Caesar cipher
void encrypt(char* message, char* key) {
    int i, j, k;
    int message_length = strlen(message);

    // Convert key to uppercase
    for(i=0; key[i]!='\0'; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the message
    for(i=0; i<message_length; i++) {
        if(isalpha(message[i])) {
            // Check if the letter is uppercase or lowercase
            if(isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A' + key[i % KEY_SIZE] - 'A') % ALPHABET_SIZE);
            } else {
                message[i] = 'a' + ((message[i] - 'a' + key[i % KEY_SIZE] - 'a') % ALPHABET_SIZE);
            }
        }
    }
}

int main() {
    char message[1000], key[16];

    // Get the message to be encrypted
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    // Get the encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}