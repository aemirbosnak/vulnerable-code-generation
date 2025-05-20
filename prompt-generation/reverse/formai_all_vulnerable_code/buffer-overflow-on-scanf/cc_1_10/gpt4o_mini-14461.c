//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

// Function prototypes
void encrypt(const char *input, char *output, int key);
void decrypt(const char *input, char *output, int key);
void to_upper_case(char *str);

int main() {
    char input[MAX_INPUT_LENGTH];
    char encrypted[MAX_INPUT_LENGTH];
    char decrypted[MAX_INPUT_LENGTH];
    int key;
    
    printf("Ah, my dear Watson! I see you're intrigued by the powers of encryption.\n");
    printf("But first, we must ask: What is our secret key? (It must be a positive integer): ");
    
    // Accepting the key
    if (scanf("%d", &key) != 1 || key <= 0) {
        fprintf(stderr, "Alas! That is not a valid key. The game must end here.\n");
        return 1;
    }
    
    // Clear input buffer
    while (getchar() != '\n');

    printf("Now, tell me the message you wish to encrypt: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Encrypt the message
    encrypt(input, encrypted, key);
    printf("The encrypted message is: %s\n", encrypted);
    
    // Decrypt the message
    decrypt(encrypted, decrypted, key);
    printf("The decrypted message is: %s\n", decrypted);
    
    return 0;
}

// Function to encrypt a string using a simple Caesar Cipher method
void encrypt(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Shift characters within the bounds of A-Z and a-z
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            output[i] = (input[i] - base + key) % 26 + base;
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the string
}

// Function to decrypt a string using the Caesar Cipher method
void decrypt(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Shift characters in the opposite direction
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            output[i] = (input[i] - base - key + 26) % 26 + base; // +26 to handle negative values
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the string
}

// Function to convert a string to upper case (not used in current implementation)
void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}