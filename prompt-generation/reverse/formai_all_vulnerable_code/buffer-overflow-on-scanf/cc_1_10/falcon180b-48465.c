//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using Caesar cipher
void caesar_encrypt(char *message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
    }
}

// Function to decrypt the message using Caesar cipher
void caesar_decrypt(char *message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key - 65 + 26) % 26 + 65;
            } else {
                message[i] = (message[i] - key - 97 + 26) % 26 + 97;
            }
        }
    }
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    // Encrypt the message
    caesar_encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesar_decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}