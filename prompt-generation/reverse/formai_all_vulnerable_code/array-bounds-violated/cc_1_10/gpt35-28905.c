//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of our key
#define KEY_SIZE 24

// Define the size of our input buffer
#define BUFFER_SIZE 1024

// Our encryption function
void encrypt(char *input, char *output, char *key) {
    // Set up our indexes
    int i, j = 0;
    int key_length = strlen(key);
    int input_length = strlen(input);
    
    // Encrypt each character of the input string
    for (i = 0; i < input_length; i++) {
        // Get the corresponding index in our key
        int key_index = j % key_length;
        
        // Get the character to encrypt
        char c = input[i];
        
        // Perform the encryption using XOR
        output[i] = c ^ key[key_index];
        
        // Increment our index into the key
        j++;
    }
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    char key[KEY_SIZE];
    
    // Get the input string
    printf("Enter the string to encrypt: ");
    fgets(input, BUFFER_SIZE, stdin);
    
    // Remove the newline character from fgets
    input[strlen(input) - 1] = '\0';
    
    // Get the encryption key
    printf("Enter the encryption key: ");
    fgets(key, KEY_SIZE, stdin);
    
    // Remove the newline character from fgets
    key[strlen(key) - 1] = '\0';
    
    // Call the encryption function
    encrypt(input, output, key);
    
    // Print the resulting encrypted string
    printf("Encrypted string: %s\n", output);
    
    return 0;
}