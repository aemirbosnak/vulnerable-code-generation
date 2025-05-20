//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64

// Character sets for password generation
char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char number_chars[] = "0123456789";
char symbol_chars[] = "!@#$%^&*()_+=-/";

// Function to generate a random password
char *generate_password(int length, int lowercase, int uppercase, int number, int symbol) {
    // Allocate memory for the password
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    // Initialize the password to all zeros
    memset(password, 0, length + 1);

    // Generate a random seed
    srand(time(NULL));

    // Generate the password
    int i;
    for (i = 0; i < length; i++) {
        int char_type = rand() % 4;
        switch (char_type) {
            case 0:
                // Lowercase character
                password[i] = lowercase_chars[rand() % strlen(lowercase_chars)];
                break;
            case 1:
                // Uppercase character
                password[i] = uppercase_chars[rand() % strlen(uppercase_chars)];
                break;
            case 2:
                // Number
                password[i] = number_chars[rand() % strlen(number_chars)];
                break;
            case 3:
                // Symbol
                password[i] = symbol_chars[rand() % strlen(symbol_chars)];
                break;
        }
    }

    // Return the password
    return password;
}

// Main function
int main() {
    // Get the password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Get the character set options from the user
    int lowercase, uppercase, number, symbol;
    printf("Include lowercase characters? (0 for no, 1 for yes): ");
    scanf("%d", &lowercase);
    printf("Include uppercase characters? (0 for no, 1 for yes): ");
    scanf("%d", &uppercase);
    printf("Include numbers? (0 for no, 1 for yes): ");
    scanf("%d", &number);
    printf("Include symbols? (0 for no, 1 for yes): ");
    scanf("%d", &symbol);

    // Generate the password
    char *password = generate_password(length, lowercase, uppercase, number, symbol);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}