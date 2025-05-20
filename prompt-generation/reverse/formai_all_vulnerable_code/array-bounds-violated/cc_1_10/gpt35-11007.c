//FormAI DATASET v1.0 Category: modern Encryption ; Style: mathematical
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int message_length = strlen(message);

    // Create cipher text string
    char ciphertext[message_length];

    // Loop through each character in the message
    for (int i = 0; i < message_length; i++) {
        // Convert the character to its ASCII value and subtract 97 to map to A=0, B=1, etc.
        int char_value = message[i] - 97;

        // Apply the encryption formula: C = (m + k) mod 26
        int cipher_value = (char_value + key) % 26;

        // Convert the cipher value back to a character by adding 97
        char ciphertext_char = cipher_value + 97;

        // Add the cipher character to the ciphertext string
        ciphertext[i] = ciphertext_char;
    }

    // Append the null terminator to the ciphertext string
    ciphertext[message_length] = '\0';

    printf("\nEncrypted message: %s\n", ciphertext);
}

void decrypt(char *message, int key) {
    int message_length = strlen(message);

    // Create plaintext string
    char plaintext[message_length];

    // Loop through each character in the message
    for (int i = 0; i < message_length; i++) {
        // Convert the character to its ASCII value and subtract 97 to map to A=0, B=1, etc.
        int char_value = message[i] - 97;

        // Apply the decryption formula: m = (C - k) mod 26
        int plain_value = (char_value - key) % 26;

        // Handle negative values by adding 26
        if (plain_value < 0) {
            plain_value += 26;
        }

        // Convert the plain value back to a character by adding 97
        char plaintext_char = plain_value + 97;

        // Add the plain character to the plaintext string
        plaintext[i] = plaintext_char;
    }

    // Append the null terminator to the plaintext string
    plaintext[message_length] = '\0';

    printf("\nDecrypted message: %s\n", plaintext);
}

int main() {
    char message[100];
    int key;

    // Prompt user for message and key
    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    // Call encryption function
    encrypt(message, key);

    // Call decryption function
    decrypt(message, key);

    return 0;
}