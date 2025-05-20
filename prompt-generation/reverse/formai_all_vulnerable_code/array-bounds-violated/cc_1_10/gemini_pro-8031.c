//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>

// An array of all lowercase English alphabet characters
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

// A function to encrypt a single character using the Caesar cipher
char encrypt_char(char c, int key) {
    // Get the index of the character in the alphabet array
    int index = c - 'a';

    // Add the key to the index and wrap around if necessary
    index = (index + key) % 26;

    // Return the encrypted character
    return alphabet[index];
}

// A function to decrypt a single character using the Caesar cipher
char decrypt_char(char c, int key) {
    // Get the index of the character in the alphabet array
    int index = c - 'a';

    // Subtract the key from the index and wrap around if necessary
    index = (index - key) % 26;

    // Return the decrypted character
    return alphabet[index];
}

int main() {
    // The secret message to encrypt
    char message[] = "Meet me at the park at midnight";

    // The encryption key
    int key = 3;

    // Encrypt the message using the Caesar cipher
    for (int i = 0; i < strlen(message); i++) {
        message[i] = encrypt_char(message[i], key);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the Caesar cipher
    for (int i = 0; i < strlen(message); i++) {
        message[i] = decrypt_char(message[i], key);
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}