//FormAI DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Encrypts the input using Ceaser cipher with the provided shift 
 * key and returns the encrypted string.
 */
char* encrypt(char *input, int shiftKey) {
    int length = strlen(input);
    char *encrypted = malloc(length * sizeof(char));
    
    // Loop through each character and shift by the provided key
    for(int i = 0; i < length; i++) {
        // Check if the character is lowercase
        if(input[i] >= 'a' && input[i] <= 'z') {
            // Shift the letter by the provided key, wrapping around if needed
            encrypted[i] = ((input[i] - 'a' + shiftKey) % 26) + 'a';
        }
        // Check if the character is uppercase
        else if(input[i] >= 'A' && input[i] <= 'Z') {
            // Shift the letter by the provided key, wrapping around if needed
            encrypted[i] = ((input[i] - 'A' + shiftKey) % 26) + 'A';
        }
        // If the character is not a letter, leave it unchanged
        else {
            encrypted[i] = input[i];
        }
    }
    
    return encrypted;
}

int main() {
    char input[100];
    int shiftKey;

    // Ask the user for input and the shift key
    printf("Enter a word or phrase to encrypt: ");
    fgets(input, 100, stdin);
    printf("Enter the shift key: ");
    scanf("%d", &shiftKey);

    // Encrypt the input and print the result
    char *encrypted = encrypt(input, shiftKey);
    printf("Encrypted message: %s\n", encrypted);

    // Free the memory used by the encrypted string
    free(encrypted);

    return 0;
}