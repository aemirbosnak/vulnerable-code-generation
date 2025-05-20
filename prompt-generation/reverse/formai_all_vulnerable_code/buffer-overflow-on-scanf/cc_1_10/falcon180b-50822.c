//Falcon-180B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the key
#define KEY_SIZE 16

// Define the encryption and decryption functions
void encrypt(char* input, char* key, char* output);
void decrypt(char* input, char* key, char* output);

// Define the main function
int main() {
    // Define the input string
    char input[100];

    // Prompt the user to enter the input string
    printf("Enter the input string: ");
    scanf("%s", input);

    // Define the key
    char key[KEY_SIZE];

    // Prompt the user to enter the key
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the input string using the key
    char encrypted[100];
    encrypt(input, key, encrypted);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the encrypted string using the key
    char decrypted[100];
    decrypt(encrypted, key, decrypted);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}

// Define the encryption function
void encrypt(char* input, char* key, char* output) {
    // Initialize the output string
    memset(output, 0, strlen(input));

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Get the ASCII value of the input character
        int input_char = input[i];

        // Get the ASCII value of the key character
        int key_char = key[i % KEY_SIZE];

        // Calculate the encrypted character
        int encrypted_char = input_char ^ key_char;

        // Convert the encrypted character to a printable character
        char encrypted_char_str[3];
        sprintf(encrypted_char_str, "%02X", encrypted_char);

        // Append the encrypted character to the output string
        strcat(output, encrypted_char_str);
    }
}

// Define the decryption function
void decrypt(char* input, char* key, char* output) {
    // Initialize the output string
    memset(output, 0, strlen(input));

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Get the ASCII value of the input character
        int input_char = input[i];

        // Get the ASCII value of the key character
        int key_char = key[i % KEY_SIZE];

        // Calculate the decrypted character
        int decrypted_char = input_char ^ key_char;

        // Convert the decrypted character to a printable character
        char decrypted_char_str[3];
        sprintf(decrypted_char_str, "%02X", decrypted_char);

        // Append the decrypted character to the output string
        strcat(output, decrypted_char_str);
    }
}