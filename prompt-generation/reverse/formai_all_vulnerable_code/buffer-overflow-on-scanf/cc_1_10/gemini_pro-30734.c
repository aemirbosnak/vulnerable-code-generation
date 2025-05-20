//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for the password
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Get a random number within a range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate a random character from a character set
char get_random_character(char *charset) {
    int index = get_random_number(0, strlen(charset) - 1);
    return charset[index];
}

// Generate a random password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Choose a random character set
        int charset_index = get_random_number(0, 3);
        char *charset = NULL;
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

        // Append a random character from the chosen character set to the password
        password[i] = get_random_character(charset);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Print the generated password to the console
void print_password(char *password) {
    printf("Generated password: %s\n", password);
}

// Get the length of the password from the user
int get_password_length() {
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);
    return length;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length = get_password_length();

    // Generate a random password
    char *password = generate_password(length);

    // Print the generated password to the console
    print_password(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}