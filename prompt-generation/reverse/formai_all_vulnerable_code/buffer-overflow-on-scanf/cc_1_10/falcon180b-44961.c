//Falcon-180B DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define KEY_SIZE 13

// Function to encrypt the given string using Caesar cipher
void encrypt(char* str, int key) {
    int i = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = 'A' + ((str[i] - 'A' + key) % ALPHABET_SIZE);
            } else {
                str[i] = 'a' + ((str[i] - 'a' + key) % ALPHABET_SIZE);
            }
        }
        i++;
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char* str, int key) {
    int i = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = 'A' + ((str[i] - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE);
            } else {
                str[i] = 'a' + ((str[i] - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE);
            }
        }
        i++;
    }
}

// Function to generate a random key of given length
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % ALPHABET_SIZE;
    }
    key[length] = '\0';
}

int main() {
    char message[1000];
    char key[KEY_SIZE];
    int message_length, key_length;

    // Get the message and the key from the user
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);
    message_length = strlen(message);
    printf("Enter the key length (between 1 and %d): ", KEY_SIZE - 1);
    scanf("%d", &key_length);
    generate_key(key, key_length);

    // Encrypt the message using the key
    encrypt(message, key_length);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the same key
    decrypt(message, key_length);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}