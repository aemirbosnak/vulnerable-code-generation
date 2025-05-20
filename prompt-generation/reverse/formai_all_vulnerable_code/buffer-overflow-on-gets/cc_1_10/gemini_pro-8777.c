//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Define the encryption function
char* encrypt(char *plaintext) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Initialize the index and the key index
    int i = 0, j = 0;

    // Iterate over the plaintext
    while (plaintext[i] != '\0') {
        // Encrypt the current character
        ciphertext[i] = plaintext[i] ^ KEY[j];

        // Increment the index and the key index
        i++;
        j++;

        // Reset the key index if necessary
        if (j == strlen(KEY)) {
            j = 0;
        }
    }

    // Terminate the ciphertext
    ciphertext[i] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Define the decryption function
char* decrypt(char *ciphertext) {
    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Initialize the index and the key index
    int i = 0, j = 0;

    // Iterate over the ciphertext
    while (ciphertext[i] != '\0') {
        // Decrypt the current character
        plaintext[i] = ciphertext[i] ^ KEY[j];

        // Increment the index and the key index
        i++;
        j++;

        // Reset the key index if necessary
        if (j == strlen(KEY)) {
            j = 0;
        }
    }

    // Terminate the plaintext
    plaintext[i] = '\0';

    // Return the plaintext
    return plaintext;
}

// Define the main function
int main() {
    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext: ");
    gets(plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("The decrypted plaintext is: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}