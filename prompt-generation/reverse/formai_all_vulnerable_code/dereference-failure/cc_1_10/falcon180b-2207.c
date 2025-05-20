//Falcon-180B DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000

// Function to encrypt the input string using the given key
char* encrypt(char* input, char* key) {
    char* encrypted = malloc(strlen(input) + 1);
    int key_length = strlen(key);
    int input_length = strlen(input);
    int i = 0;

    // Loop through the input string
    for (int j = 0; j < input_length; j++) {
        // Convert the input character to uppercase
        char c = toupper(input[j]);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Calculate the shift value
            int shift = c - 'A';

            // Check if the shift value is negative
            if (shift < 0) {
                shift += 26;
            }

            // Apply the shift to the character
            c = (char) (((c - 'A' + key_length - 1) % 26) + 'A');
        }

        // Add the encrypted character to the output string
        encrypted[i++] = c;
    }

    encrypted[i] = '\0';

    return encrypted;
}

// Function to decrypt the input string using the given key
char* decrypt(char* input, char* key) {
    char* decrypted = malloc(strlen(input) + 1);
    int key_length = strlen(key);
    int input_length = strlen(input);
    int i = 0;

    // Loop through the input string
    for (int j = 0; j < input_length; j++) {
        // Convert the input character to uppercase
        char c = toupper(input[j]);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Calculate the shift value
            int shift = c - 'A';

            // Check if the shift value is negative
            if (shift < 0) {
                shift += 26;
            }

            // Apply the shift to the character
            c = (char) (((c - 'A' - key_length + 26) % 26) + 'A');
        }

        // Add the decrypted character to the output string
        decrypted[i++] = c;
    }

    decrypted[i] = '\0';

    return decrypted;
}

int main() {
    char* input = malloc(MAX_INPUT_LENGTH);
    char* key = malloc(MAX_KEY_LENGTH);

    // Prompt the user for the input string
    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Prompt the user for the encryption key
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove the newline character from the input and key strings
    input[strcspn(input, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the input string using the key
    char* encrypted = encrypt(input, key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the encrypted string using the key
    char* decrypted = decrypt(encrypted, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted);

    free(input);
    free(key);
    free(encrypted);
    free(decrypted);

    return 0;
}