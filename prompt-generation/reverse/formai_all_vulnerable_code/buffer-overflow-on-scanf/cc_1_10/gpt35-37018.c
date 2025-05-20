//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the function to generate random passwords
void generatePassword(int length) {

    // Set the allowed characters for the passwords
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    // Calculate the total number of characters in the allowed characters string
    int numCharacters = sizeof(characters) - 1;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    printf("\nYour new password is:\n");
    for(int i = 0; i < length; i++) {
        printf("%c", characters[rand() % numCharacters]);
    }
    printf("\n");
}

int main() {

    // Define variables to hold user input
    int passwordLength;

    // Greet the user and explain what the program does
    printf("Welcome to the Secure Password Generator!\n\n");
    printf("This program will generate a secure password for you, based on your chosen length.\n\n");

    // Prompt the user to enter the desired length of the password
    printf("Please enter the desired length of your password (between 8 and 20 characters): ");
    scanf("%d", &passwordLength);

    // Check if the password length is within valid range
    if(passwordLength >= 8 && passwordLength <= 20) {
        // Call the function to generate the password
        generatePassword(passwordLength);
    } else {
        printf("\nPassword length must be between 8 and 20 characters. Please try again.\n");
        // Prompt the user to re-enter the desired length of the password
        printf("\nPlease enter the desired length of your password (between 8 and 20 characters): ");
        scanf("%d", &passwordLength);
        // Call the function to generate the password
        generatePassword(passwordLength);
    }

    // Say thank you to the user and end the program
    printf("\nThank you for using the Secure Password Generator! Goodbye!\n");

    return 0;
}