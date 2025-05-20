//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100 // maximum length of password

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_count = 0;

    // prompt user for password
    printf("Enter password: ");
    scanf("%s", password);

    // check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 1;
    }

    // check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // calculate password strength
    int strength = 0;
    if (length >= 12) {
        strength++;
    }
    if (uppercase_count >= 1) {
        strength++;
    }
    if (lowercase_count >= 1) {
        strength++;
    }
    if (digit_count >= 1) {
        strength++;
    }
    if (special_count >= 1) {
        strength++;
    }

    // display password strength
    if (strength == 0) {
        printf("Very weak password.\n");
    } else if (strength == 1) {
        printf("Weak password.\n");
    } else if (strength == 2) {
        printf("Moderate password.\n");
    } else if (strength == 3) {
        printf("Strong password.\n");
    } else if (strength == 4) {
        printf("Very strong password.\n");
    }

    return 0;
}