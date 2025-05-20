//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the alphabet to be used
#define ALPHABET_SIZE 26
char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

int main() {
    char message[100];
    char key[100];
    char encrypted_message[100];
    char decrypted_message[100];

    // Get user input for message and key
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);

    // Encrypt message using Caesar cipher
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i = 0;
    int j = 0;
    while (i < message_length) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = alphabet[(int)message[i] - 65 + (int)key[j] - 97] % ALPHABET_SIZE;
            } else {
                encrypted_message[i] = alphabet[(int)message[i] - 97 + (int)key[j] - 97] % ALPHABET_SIZE;
            }
            j++;
            if (j == key_length) {
                j = 0;
            }
        } else {
            encrypted_message[i] = message[i];
        }
        i++;
    }

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message using Caesar cipher
    int decrypted_message_length = strlen(encrypted_message);
    i = 0;
    j = 0;
    while (i < decrypted_message_length) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = alphabet[(int)encrypted_message[i] - 65 - (int)key[j] + 97] % ALPHABET_SIZE;
            } else {
                decrypted_message[i] = alphabet[(int)encrypted_message[i] - 97 - (int)key[j] + 97] % ALPHABET_SIZE;
            }
            j++;
            if (j == key_length) {
                j = 0;
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
        i++;
    }

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}