//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_CIPHER_LENGTH 1000

// Function to encrypt the input string using the given key
void encrypt(char* input, char* key) {
    int key_length = strlen(key);
    int i, j;
    char cipher[MAX_CIPHER_LENGTH];
    cipher[0] = '\0';

    // Add the key to the input string
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                cipher[i] = (input[i] + key_length - 65) % 26 + 65;
            } else {
                cipher[i] = (input[i] + key_length - 97) % 26 + 97;
            }
        } else {
            cipher[i] = input[i];
        }
    }

    // Print the encrypted string
    printf("Encrypted string: %s\n", cipher);
}

// Function to decrypt the input string using the given key
void decrypt(char* cipher, char* key) {
    int key_length = strlen(key);
    int i, j;
    char input[MAX_CIPHER_LENGTH];
    input[0] = '\0';

    // Remove the key from the cipher string
    for (i = 0; i < strlen(cipher); i++) {
        if (isalpha(cipher[i])) {
            if (isupper(cipher[i])) {
                input[i] = (cipher[i] - key_length - 65) % 26 + 65;
            } else {
                input[i] = (cipher[i] - key_length - 97) % 26 + 97;
            }
        } else {
            input[i] = cipher[i];
        }
    }

    // Print the decrypted string
    printf("Decrypted string: %s\n", input);
}

int main() {
    char input[MAX_CIPHER_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the input string using the given key
    encrypt(input, key);

    // Decrypt the encrypted string using the same key
    decrypt(input, key);

    return 0;
}