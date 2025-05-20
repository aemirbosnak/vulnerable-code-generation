//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for the password
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+"

// Get a random number within a range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate a random character from a character set
char get_random_character(const char *charset) {
    int index = get_random_number(0, strlen(charset) - 1);
    return charset[index];
}

// Generate a random password
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Choose a random character set
        int charset_index = get_random_number(0, 3);
        const char *charset;

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

        // Get a random character from the character set
        password[i] = get_random_character(charset);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Print the password
void print_password(char *password) {
    printf("Your password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
    free(password);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password you want: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_password(length);

    // Print the password
    print_password(password);

    // Free the memory allocated for the password
    free_password(password);

    return 0;
}