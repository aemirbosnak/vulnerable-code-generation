//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_UPPERCASE 0x01
#define CHAR_CLASS_LOWERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SPECIAL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Function to check if a character is in a given character class
int is_char_in_class(char c, int char_class) {
    switch (char_class) {
        case CHAR_CLASS_UPPERCASE:
            return isupper(c);
        case CHAR_CLASS_LOWERCASE:
            return islower(c);
        case CHAR_CLASS_DIGIT:
            return isdigit(c);
        case CHAR_CLASS_SPECIAL:
            return !isalnum(c);
        default:
            return 0;
    }
}

// Function to calculate the password strength
int calculate_password_strength(char *password) {
    int password_strength = 0;

    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check the character classes
    int char_classes = 0;
    if (is_char_in_class(password[0], CHAR_CLASS_UPPERCASE)) {
        char_classes |= CHAR_CLASS_UPPERCASE;
    }
    if (is_char_in_class(password[0], CHAR_CLASS_LOWERCASE)) {
        char_classes |= CHAR_CLASS_LOWERCASE;
    }
    if (is_char_in_class(password[0], CHAR_CLASS_DIGIT)) {
        char_classes |= CHAR_CLASS_DIGIT;
    }
    if (is_char_in_class(password[0], CHAR_CLASS_SPECIAL)) {
        char_classes |= CHAR_CLASS_SPECIAL;
    }

    // Check the number of character classes
    if (char_classes == 1) {
        password_strength = PASSWORD_STRENGTH_WEAK;
    } else if (char_classes == 2) {
        password_strength = PASSWORD_STRENGTH_MEDIUM;
    } else if (char_classes >= 3) {
        password_strength = PASSWORD_STRENGTH_STRONG;
    }

    // Check the password history
    // ...

    // Return the password strength
    return password_strength;
}

// Function to get the password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);
    if (password == NULL) {
        return NULL;
    }

    printf("Enter your password: ");
    scanf("%s", password);

    return password;
}

// Function to print the password strength
void print_password_strength(int password_strength) {
    switch (password_strength) {
        case PASSWORD_STRENGTH_WEAK:
            printf("Your password is weak.\n");
            break;
        case PASSWORD_STRENGTH_MEDIUM:
            printf("Your password is medium.\n");
            break;
        case PASSWORD_STRENGTH_STRONG:
            printf("Your password is strong.\n");
            break;
        default:
            printf("Invalid password strength.\n");
            break;
    }
}

// Main function
int main() {
    // Get the password from the user
    char *password = get_password();
    if (password == NULL) {
        printf("Error: Could not allocate memory for password.\n");
        return 1;
    }

    // Calculate the password strength
    int password_strength = calculate_password_strength(password);

    // Print the password strength
    print_password_strength(password_strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}