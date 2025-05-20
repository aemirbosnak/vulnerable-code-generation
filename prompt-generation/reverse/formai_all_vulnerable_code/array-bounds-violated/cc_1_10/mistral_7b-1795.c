//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MAX_TRIES 3

// Function to check if a character is valid
int is_valid_char(char c) {
    return (isalnum(c) || (isdigit(c) && !(strchr("0123456", c) - strchr(0, c) < 3)) || strchr("!@#$%^&*()-_+=[]{}|;:,.<>/?`~", c));
}

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digits = 0, specials = 0;
    int complexity = 0;

    // Check for minimum length
    if (length < MIN_LENGTH) {
        printf("Password is too short!\n");
        return 0;
    }

    // Check for presence of uppercase, lowercase, digits and specials
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digits++;
        } else if (is_valid_char(password[i])) {
            specials++;
        }
    }

    // Check for complexity rules
    if (uppercase && lowercase && digits && specials) {
        complexity = 1;
    }

    // Determine password strength based on complexity and length
    if (complexity && length > MIN_LENGTH) {
        printf("Strong Password!\n");
        return 1;
    } else {
        printf("Weak Password!\n");
        return 0;
    }
}

// Function to read password from user and check its strength
int main() {
    char password[MIN_LENGTH + 1];
    int tries = 0;

    printf("Create a strong password!\n");
    while (1) {
        printf("Enter your password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        // Remove leading whitespaces
        for (int i = 0; password[i]; i++) {
            if (isspace(password[i])) {
                for (int j = i; password[j]; j++) {
                    password[j - 1] = password[j];
                }
                i--;
                break;
            }
        }

        // Check password strength
        int strength = check_password_strength(password);
        if (strength) {
            break;
        }

        // If password is weak, ask user to try again
        printf("Password is weak! Try again.\n");
        tries++;
        if (tries >= MAX_TRIES) {
            printf("You have reached the maximum number of tries.\n");
            return 1;
        }
    }

    printf("Congratulations, your password is strong!\n");
    return 0;
}