//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 42

// Function to encrypt a single character
char encrypt_char(char c) {
    return (c + KEY) % 26 + 'A';
}

// Function to decrypt a single character
char decrypt_char(char c) {
    return (c - KEY) % 26 + 'A';
}

// Function to encrypt a string
void encrypt(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = encrypt_char(str[i]);
        }
    }
}

// Function to decrypt a string
void decrypt(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = decrypt_char(str[i]);
        }
    }
}

int main() {
    // Prompt user for input
    printf("Enter a string to encrypt: ");
    char input[100];
    scanf("%s", input);

    // Encrypt the input string
    encrypt(input);

    // Display the encrypted string
    printf("Encrypted string: %s\n", input);

    // Prompt user for input
    printf("Enter the encrypted string to decrypt: ");
    scanf("%s", input);

    // Decrypt the input string
    decrypt(input);

    // Display the decrypted string
    printf("Decrypted string: %s\n", input);

    return 0;
}