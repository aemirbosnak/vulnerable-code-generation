//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets to use for password generation
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_-=+?"

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Function to generate a random number between two values
int generate_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character from a character set
char generate_random_character(const char *charset) {
    int index = generate_random_number(0, strlen(charset) - 1);
    return charset[index];
}

// Function to generate a random password
char *generate_random_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Choose a random character set
        const char *charset = NULL;
        int charset_index = generate_random_number(0, 3);
        switch (charset_index) {
            case 0:
                charset = CHARSET_LOWERCASE;
                break;
            case 1:
                charset = CHARSET_UPPERCASE;
                break;
            case 2:
                charset = CHARSET_DIGITS;
                break;
            case 3:
                charset = CHARSET_SYMBOLS;
                break;
        }

        // Generate a random character from the chosen character set
        char character = generate_random_character(charset);

        // Add the character to the password
        password[i] = character;
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user for the desired password length
    int length;
    printf("Enter the desired password length (minimum %d, maximum %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    // Check if the password length is valid
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Generate a random password
    char *password = generate_random_password(length);

    // Print the generated password
    printf("Your randomly generated password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}