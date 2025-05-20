//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

// Function to generate a random character
char generate_random_character() {
    // Generate a random number between 33 and 126
    int random_number = rand() % (126 - 33 + 1) + 33;

    // Return the character corresponding to the random number
    return (char)random_number;
}

// Function to generate a random password
char *generate_random_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate a random character for each position in the password
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character();
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the password length from the user
    int password_length;
    printf("Enter the desired password length: ");
    scanf("%d", &password_length);

    // Generate a random password
    char *password = generate_random_password(password_length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}