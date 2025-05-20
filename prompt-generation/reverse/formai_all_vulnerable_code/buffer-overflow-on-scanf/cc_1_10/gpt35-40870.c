//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a secure password
char* generatePassword(int length) {

    // Define the character set for the password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*";

    // Get the length of the character set
    int charsetLength = strlen(charset);

    // Seed the random number generator
    srand(time(NULL));

    // Create a password array to store the generated password
    char* password = malloc(sizeof(char) * (length + 1));

    // Loop through and set each character of the password
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    // Add a null terminating character to the end of the password string
    password[length] = '\0';

    // Return the generated password
    return password;
}

int main() {

    int passwordLength;

    printf("Welcome to the Secure Password Generator!\n\n");

    printf("How long would you like your password to be? (Please enter a number between 8 and 32): ");

    // Get password length from user input
    scanf("%d", &passwordLength);

    // Make sure password length is within the specified range
    if (passwordLength < 8 || passwordLength > 32) {
        printf("\nInvalid password length. Please enter a number between 8 and 32.\n");
        return 0;
    }

    printf("\nGenerating your password...\n");

    // Generate the password
    char* password = generatePassword(passwordLength);

    // Print the generated password
    printf("Your new secure password is: %s\n\n", password);

    // Free memory used by password array
    free(password);

    printf("Thank you for using the Secure Password Generator! Goodbye!\n");

    return 0;
}