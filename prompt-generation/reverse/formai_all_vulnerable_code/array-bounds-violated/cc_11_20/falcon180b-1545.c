//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;
    int password_strength = 0;

    printf("Welcome to the password strength checker!\n");

    do {
        printf("Enter a password (minimum length of %d characters): ", MIN_PASSWORD_LENGTH);
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password_length = strlen(password);

        // Remove newline character from the end of the password
        password[password_length - 1] = '\0';

        // Check for lowercase characters
        for (int i = 0; i < password_length; i++) {
            if (islower(password[i])) {
                lowercase_count++;
            }
        }

        // Check for uppercase characters
        for (int i = 0; i < password_length; i++) {
            if (isupper(password[i])) {
                uppercase_count++;
            }
        }

        // Check for digits
        for (int i = 0; i < password_length; i++) {
            if (isdigit(password[i])) {
                digit_count++;
            }
        }

        // Check for special characters
        for (int i = 0; i < password_length; i++) {
            if (!isalnum(password[i])) {
                special_character_count++;
            }
        }

        // Calculate password strength
        password_strength = (password_length > MIN_PASSWORD_LENGTH) + lowercase_count + uppercase_count + digit_count + special_character_count;

        // Print password strength
        printf("Password strength: ");
        for (int i = 0; i < 5; i++) {
            if (i < password_strength) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");

    } while (password_strength < 5);

    printf("Password is strong enough!\n");

    return 0;
}