//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if the password is strong enough
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check if the password meets the minimum requirements
    if (length < 8 ||!has_uppercase ||!has_lowercase ||!has_number ||!has_special_char) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_LENGTH];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    if (check_password_strength(password)) {
        printf("Your password is strong enough.\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}