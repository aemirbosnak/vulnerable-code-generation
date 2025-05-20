//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length,
        lowercase = 0,
        uppercase = 0,
        numbers = 0,
        specialChars = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '~') {
            specialChars = 1;
            break;
        }
    }

    if (lowercase && uppercase && numbers && specialChars) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}