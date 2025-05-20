//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "mysecretkey"

// Define the encryption function
void encrypt(char* input, char* output) {
    int i = 0;
    int j = 0;
    int n = strlen(input);

    // Iterate through the input string
    while (i < n) {
        // Get the current character
        char c = input[i];

        // Check if the character is a letter
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Encrypt the letter using the key
            char encrypted_c = ((c - 'a' + 13) % 26) + 'a';

            // Append the encrypted letter to the output string
            output[j] = encrypted_c;
            j++;
        } else {
            // Append the current character to the output string
            output[j] = c;
            j++;
        }

        // Move to the next character in the input string
        i++;
    }

    output[j] = '\0';
}

// Define the decryption function
void decrypt(char* input, char* output) {
    int i = 0;
    int j = 0;
    int n = strlen(input);

    // Iterate through the input string
    while (i < n) {
        // Get the current character
        char c = input[i];

        // Check if the character is a letter
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Decrypt the letter using the key
            char decrypted_c = ((c - 'a' - 13) % 26) + 'a';

            // Append the decrypted letter to the output string
            output[j] = decrypted_c;
            j++;
        } else {
            // Append the current character to the output string
            output[j] = c;
            j++;
        }

        // Move to the next character in the input string
        i++;
    }

    output[j] = '\0';
}

// Define the main function
int main() {
    char input[100];
    char output[200];

    // Get input from the user
    printf("Enter the text to encrypt: ");
    scanf("%s", input);

    // Encrypt the input text
    encrypt(input, output);

    // Print the encrypted text
    printf("Encrypted text: %s\n", output);

    // Decrypt the encrypted text
    decrypt(output, input);

    // Print the decrypted text
    printf("Decrypted text: %s\n", input);

    return 0;
}