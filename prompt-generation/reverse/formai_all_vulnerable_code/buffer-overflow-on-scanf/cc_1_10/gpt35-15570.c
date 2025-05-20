//FormAI DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a Modern Encryption Algorithm
char* encrypt_message(char* message, int shift) {
    // Allocate memory for encrypted message
    char* encrypted_message = (char*) malloc(strlen(message) * sizeof(char));

    // Iterate through each character in message
    for(int i=0; i<strlen(message); i++) {
        // Get ASCII value of current character
        int ascii_value = (int) message[i];

        // Shift character by specified shift amount
        ascii_value += shift;

        // If shifted value exceeds ASCII value of 'z', wrap around to 'a'
        if(ascii_value > 122) {
            ascii_value = (ascii_value % 122) + 96;
        }

        // Update encrypted message with shifted character
        encrypted_message[i] = (char) ascii_value;
    }

    // Add null terminator to encrypted message
    encrypted_message[strlen(message)] = '\0';

    return encrypted_message;
}

int main() {
    printf("Welcome to the Modern Encryption program! Let's encrypt your message!\n");

    // Get user input for message and shift amount
    char message[1000];
    int shift;

    printf("Please enter your message: ");
    fgets(message, 1000, stdin);

    printf("Please enter a shift amount (between 1-25): ");
    scanf("%d", &shift);

    // Encrypt message using Modern Encryption Algorithm
    char* encrypted_message = encrypt_message(message, shift);

    // Print out encrypted message
    printf("Your encrypted message is: %s\n", encrypted_message);

    // Free allocated memory for encrypted message
    free(encrypted_message);

    printf("Thank you for using the Modern Encryption program. Have a great day!\n");

    return 0;
}