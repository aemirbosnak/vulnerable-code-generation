//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int i;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for number
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_character = 1;
            break;
        }
    }

    // Check password strength
    if (has_uppercase && has_lowercase && has_number && has_special_character) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}