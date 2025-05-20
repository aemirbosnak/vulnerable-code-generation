//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if the password is strong enough
int check_password_strength(char *password) {
    int length = strlen(password);

    // Check if the password is too short
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check if the password contains both uppercase and lowercase letters
    int has_uppercase = 0;
    int has_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        }
    }
    if (!has_uppercase ||!has_lowercase) {
        printf("Password must contain both uppercase and lowercase letters.\n");
        return 0;
    }

    // Check if the password contains at least one number
    int has_number = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }
    if (!has_number) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    // Check if the password contains at least one special character
    int has_special_char = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }
    if (!has_special_char) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Password is strong enough
    printf("Password is strong enough.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int result = check_password_strength(password);

    // Clear the password from memory for security reasons
    memset(password, 0, MAX_PASSWORD_LENGTH);

    return result;
}