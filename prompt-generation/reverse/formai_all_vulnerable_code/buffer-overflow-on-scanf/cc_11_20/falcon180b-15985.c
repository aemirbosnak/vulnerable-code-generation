//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    length = strlen(password);

    // Check if the password is too short
    if (length < 8) {
        printf("Password is too short. Please enter a password with at least 8 characters.\n");
        return 0;
    }

    // Check if the password contains any special characters
    int has_special_char = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
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

    // Check if the password contains at least one number
    int has_number = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check if the password contains a mix of characters
    if (has_special_char && has_uppercase && has_lowercase && has_number) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak. Please choose a stronger password.\n");
    }

    return 0;
}