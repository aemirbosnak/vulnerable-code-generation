//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
// Encrypted Content Chatbot

/*
This program is a simple encryption chatbot written in C. 
It takes user input and encrypts it using a Caesar Cipher,
shifting each letter k positions to the right.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a given string
void encrypt(char str[], int k) {
    int i = 0;

    // Traverse through the string
    while (str[i]) {
        // Check if character is an uppercase letter
        if (isupper(str[i])) {
            // Apply Caesar Cipher encryption
            str[i] = ((str[i] - 'A') + k) % 26 + 'A';
        }

        // Check if character is a lowercase letter
        else if (islower(str[i])) {
            // Apply Caesar Cipher encryption
            str[i] = ((str[i] - 'a') + k) % 26 + 'a';
        }

        // Move to next character
        i++;
    }

    // Print the encrypted string
    printf("Encrypted message: %s\n", str);
}

int main() {
    // Declare variables
    char message[100];
    int shift;

    // Get user input
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove newline character from input string
    message[strcspn(message, "\n")] = 0;

    printf("Enter shift: ");
    scanf("%d", &shift);

    // Call the encrypt function
    encrypt(message, shift);

    return 0;
}