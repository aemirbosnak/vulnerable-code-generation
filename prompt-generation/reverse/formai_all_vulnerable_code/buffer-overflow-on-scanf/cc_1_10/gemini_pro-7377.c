//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*?";

// Function to generate a random number within a specified range
int generate_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random character from a specified character set
char generate_random_character(char *charset) {
    int index = generate_random_number(0, strlen(charset) - 1);
    return charset[index];
}

// Function to generate a secure password of a specified length
char *generate_secure_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate a random character from each character set
    char lowercase_char = generate_random_character(lowercase);
    char uppercase_char = generate_random_character(uppercase);
    char digit_char = generate_random_character(digits);
    char symbol_char = generate_random_character(symbols);

    // Add the random characters to the password
    password[0] = lowercase_char;
    password[1] = uppercase_char;
    password[2] = digit_char;
    password[3] = symbol_char;

    // Generate the remaining characters of the password
    for (int i = 4; i < length; i++) {
        int charset_index = generate_random_number(0, 3);
        char *charset;
        switch (charset_index) {
            case 0:
                charset = lowercase;
                break;
            case 1:
                charset = uppercase;
                break;
            case 2:
                charset = digits;
                break;
            case 3:
                charset = symbols;
                break;
        }
        password[i] = generate_random_character(charset);
    }

    // Null-terminate the password
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    // Generate a secure password
    char *password = generate_secure_password(length);

    // Print the password
    printf("Your secure password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}