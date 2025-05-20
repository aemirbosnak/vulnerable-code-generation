//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of the input string

// Function to encrypt the string using Caesar cipher
void encrypt(char *input, int shift, char *output) {
    int i;
    // Iterate through each character in the input string
    for (i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];
        // Check if the character is an uppercase letter
        if (currentChar >= 'A' && currentChar <= 'Z') {
            output[i] = (currentChar - 'A' + shift) % 26 + 'A';
        }
        // Check if the character is a lowercase letter
        else if (currentChar >= 'a' && currentChar <= 'z') {
            output[i] = (currentChar - 'a' + shift) % 26 + 'a';
        }
        // If character is not an alphabetic character, keep it unchanged
        else {
            output[i] = currentChar;
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Main function
int main() {
    char input[MAX_LEN];     // Buffer to hold the input string
    char output[MAX_LEN];    // Buffer to hold the encrypted output string
    int shift;               // Variable to hold the shift value

    // Prompt user for input
    printf("Enter a string to encrypt (max %d characters): ", MAX_LEN - 1);
    fgets(input, MAX_LEN, stdin);
    
    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Prompt user for shift value
    printf("Enter shift value (0-25): ");
    scanf("%d", &shift);
    
    // Normalize the shift value to be within 0-25
    shift = shift % 26; // Ensure shift is between 0 to 25

    // Perform encryption
    encrypt(input, shift, output);
    
    // Display the encrypted string
    printf("Encrypted string: %s\n", output);

    return 0;
}