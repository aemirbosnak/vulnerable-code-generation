//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum length of the input message
#define MAX_MSG_LENGTH 1000

// Define the size of the substitution table
#define SUBSTITUTION_TABLE_SIZE 26

// Define the substitution table
char substitution_table[SUBSTITUTION_TABLE_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// Define the Caesar cipher encryption function
void caesar_cipher_encrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = substitution_table[(int)message[i] - 65 + key] % SUBSTITUTION_TABLE_SIZE;
            } else {
                message[i] = substitution_table[(int)message[i] - 97 + key] % SUBSTITUTION_TABLE_SIZE;
            }
        }
        i++;
    }
}

// Define the Caesar cipher decryption function
void caesar_cipher_decrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = substitution_table[(int)message[i] - 65 - key + 26] % SUBSTITUTION_TABLE_SIZE;
            } else {
                message[i] = substitution_table[(int)message[i] - 97 - key + 26] % SUBSTITUTION_TABLE_SIZE;
            }
        }
        i++;
    }
}

// Define the main function
int main() {
    char message[MAX_MSG_LENGTH];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MSG_LENGTH, stdin);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the message
    caesar_cipher_encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesar_cipher_decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}