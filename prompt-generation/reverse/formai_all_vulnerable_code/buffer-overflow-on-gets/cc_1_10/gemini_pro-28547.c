//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char* encrypt(char* plaintext, int key) {
    char* ciphertext = malloc(strlen(plaintext) + 1);
    
    // Iterate over each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the character at the current index
        char c = plaintext[i];
        // Shift the character by the key
        c += key;
        // Check if the character is outside the range of printable characters
        if (c < 32 || c > 126) {
            // If so, wrap around to the beginning of the range
            c -= 95;
        }
        // Store the encrypted character in the ciphertext
        ciphertext[i] = c;
    }
    
    // Add a null terminator to the ciphertext
    ciphertext[strlen(plaintext)] = '\0';
    
    // Return the ciphertext
    return ciphertext;
}

int main() {
    // Get the plaintext and key from the user
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    gets(plaintext);
    printf("Enter the key: ");
    scanf("%d", &key);
    
    // Encrypt the plaintext
    char* ciphertext = encrypt(plaintext, key);
    
    // Print the ciphertext
    printf("The ciphertext is: %s\n", ciphertext);
    
    // Free the allocated memory
    free(ciphertext);
    
    return 0;
}