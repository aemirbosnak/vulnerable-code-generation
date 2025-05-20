//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the key size
#define KEY_SIZE 16

// Define the encryption function
void encrypt(char* input, char* key, char* output) {
    int i, j;
    char ch;

    // Initialize the output string
    for (i = 0; i < strlen(input); i++) {
        output[i] = '0';
    }

    // Encrypt the input string
    for (i = 0; i < strlen(input); i++) {
        ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + (key[i % KEY_SIZE] - 'A');
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch + (key[i % KEY_SIZE] - 'a');
        }
        else {
            ch = ch;
        }
        output[i] = ch;
    }
}

// Define the decryption function
void decrypt(char* input, char* key, char* output) {
    int i, j;
    char ch;

    // Initialize the output string
    for (i = 0; i < strlen(input); i++) {
        output[i] = '0';
    }

    // Decrypt the input string
    for (i = 0; i < strlen(input); i++) {
        ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - (key[i % KEY_SIZE] - 'A');
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch - (key[i % KEY_SIZE] - 'a');
        }
        else {
            ch = ch;
        }
        output[i] = ch;
    }
}

// Define the main function
int main() {
    char input[1000], key[KEY_SIZE], output[1000];
    int i, j;

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the input string
    encrypt(input, key, output);

    // Display the encrypted string
    printf("Encrypted string: %s\n", output);

    // Decrypt the encrypted string
    decrypt(output, key, input);

    // Display the decrypted string
    printf("Decrypted string: %s\n", input);

    return 0;
}