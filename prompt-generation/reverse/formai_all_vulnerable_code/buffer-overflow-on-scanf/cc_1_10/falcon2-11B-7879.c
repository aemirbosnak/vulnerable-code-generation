//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input string
void encrypt(char* input) {
    int key = 42; // Key for encryption
    int len = strlen(input);
    int i;
    
    // Encryption loop
    for (i = 0; i < len; i++) {
        int char_value = input[i] - 'a'; // Convert character to ASCII value
        
        // XOR with key
        char_value ^= key;
        
        // Convert back to character
        char_value += 'a';
        input[i] = char_value;
    }
    
    // Print the encrypted string
    printf("Encrypted string: %s\n", input);
}

// Function to decrypt the encrypted string
void decrypt(char* encrypted) {
    int key = 42; // Key for decryption
    int len = strlen(encrypted);
    int i;
    
    // Decryption loop
    for (i = 0; i < len; i++) {
        int char_value = encrypted[i] - 'a'; // Convert character to ASCII value
        
        // XOR with key
        char_value ^= key;
        
        // Convert back to character
        char_value += 'a';
        encrypted[i] = char_value;
    }
    
    // Print the decrypted string
    printf("Decrypted string: %s\n", encrypted);
}

int main() {
    // Prompt user for input string
    printf("Enter a string to encrypt: ");
    char* input = malloc(100 * sizeof(char));
    scanf("%s", input);
    
    // Encrypt the input string
    encrypt(input);
    
    // Prompt user for input key
    printf("Enter a key for encryption: ");
    int key;
    scanf("%d", &key);
    
    // Encrypt the input string again with the key
    encrypt(input);
    
    // Prompt user for input string
    printf("Enter a string to decrypt: ");
    char* encrypted = malloc(100 * sizeof(char));
    scanf("%s", encrypted);
    
    // Decrypt the encrypted string
    decrypt(encrypted);
    
    // Free the dynamically allocated memory
    free(input);
    free(encrypted);
    
    return 0;
}