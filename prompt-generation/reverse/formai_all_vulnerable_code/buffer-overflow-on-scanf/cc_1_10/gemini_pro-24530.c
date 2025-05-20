//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "YOUR_ENCRYPTION_KEY"

// Define the block size
#define BLOCK_SIZE 16

// Define the padding character
#define PADDING_CHAR ' '

// Function to encrypt a block of data
void encrypt_block(unsigned char *block, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

// Function to decrypt a block of data
void decrypt_block(unsigned char *block, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

// Function to pad a string to a multiple of the block size
void pad_string(unsigned char *string) {
    int length = strlen((char *)string);
    int padding = BLOCK_SIZE - (length % BLOCK_SIZE);

    for (int i = length; i < length + padding; i++) {
        string[i] = PADDING_CHAR;
    }
}

// Function to remove padding from a string
void unpad_string(unsigned char *string) {
    int length = strlen((char *)string);

    while (length > 0 && string[length - 1] == PADDING_CHAR) {
        length--;
    }

    string[length] = '\0';
}

// Function to encrypt a string
unsigned char *encrypt(unsigned char *string, unsigned char *key) {
    // Pad the string to a multiple of the block size
    pad_string(string);

    // Allocate memory for the encrypted string
    unsigned char *encrypted_string = malloc(strlen((char *)string) + 1);

    // Encrypt the string block by block
    for (int i = 0; i < strlen((char *)string); i += BLOCK_SIZE) {
        encrypt_block(&string[i], key);
    }

    // Copy the encrypted string to the buffer
    strcpy((char *)encrypted_string, (char *)string);

    // Return the encrypted string
    return encrypted_string;
}

// Function to decrypt a string
unsigned char *decrypt(unsigned char *string, unsigned char *key) {
    // Allocate memory for the decrypted string
    unsigned char *decrypted_string = malloc(strlen((char *)string) + 1);

    // Decrypt the string block by block
    for (int i = 0; i < strlen((char *)string); i += BLOCK_SIZE) {
        decrypt_block(&string[i], key);
    }

    // Remove padding from the decrypted string
    unpad_string(decrypted_string);

    // Copy the decrypted string to the buffer
    strcpy((char *)decrypted_string, (char *)string);

    // Return the decrypted string
    return decrypted_string;
}

// Main function
int main() {
    // Get the plaintext from the user
    printf("Enter the plaintext: ");
    unsigned char plaintext[1024];
    scanf("%s", plaintext);

    // Convert the key to a binary string
    unsigned char key[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        key[i] = KEY[i];
    }

    // Encrypt the plaintext
    unsigned char *encrypted_plaintext = encrypt(plaintext, key);

    // Print the encrypted plaintext
    printf("Encrypted plaintext: %s\n", encrypted_plaintext);

    // Decrypt the encrypted plaintext
    unsigned char *decrypted_plaintext = decrypt(encrypted_plaintext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(encrypted_plaintext);
    free(decrypted_plaintext);

    return 0;
}