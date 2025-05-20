//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string
char* encrypt(char* str, int key) {
    // Declare variables
    int i, len = strlen(str);
    char* enc_str = malloc(len + 1);

    // Iterate through each character of the string
    for (i = 0; i < len; i++) {
        // Get the ASCII value of the character
        int ascii = str[i];

        // Add the key to the ASCII value
        ascii += key;

        // Check if the resulting ASCII value is within the range of 0 to 255
        if (ascii > 255) {
            ascii -= 255;
        }

        // Assign the encrypted character to the encrypted string
        enc_str[i] = ascii;
    }

    // Add the null terminator to the end of the encrypted string
    enc_str[len] = '\0';

    // Return the encrypted string
    return enc_str;
}

// Function to decrypt a string
char* decrypt(char* str, int key) {
    // Declare variables
    int i, len = strlen(str);
    char* dec_str = malloc(len + 1);

    // Iterate through each character of the string
    for (i = 0; i < len; i++) {
        // Get the ASCII value of the character
        int ascii = str[i];

        // Subtract the key from the ASCII value
        ascii -= key;

        // Check if the resulting ASCII value is within the range of 0 to 255
        if (ascii < 0) {
            ascii += 255;
        }

        // Assign the decrypted character to the decrypted string
        dec_str[i] = ascii;
    }

    // Add the null terminator to the end of the decrypted string
    dec_str[len] = '\0';

    // Return the decrypted string
    return dec_str;
}

int main() {
    // Declare variables
    char str[] = "Hello World!";
    int key = 5;

    // Encrypt the string
    char* enc_str = encrypt(str, key);

    // Decrypt the encrypted string
    char* dec_str = decrypt(enc_str, key);

    // Print the original string and the encrypted and decrypted strings
    printf("Original string: %s\n", str);
    printf("Encrypted string: %s\n", enc_str);
    printf("Decrypted string: %s\n", dec_str);

    // Free memory
    free(enc_str);
    free(dec_str);

    return 0;
}