//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {

    char password[50];
    int length, has_uppercase, has_lowercase, has_digit, has_special_char;
    int i;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // initialize all booleans as false
    has_uppercase = has_lowercase = has_digit = has_special_char = 0;

    // check all characters in password
    for (i = 0; i < length; i++) {

        // check for uppercase letter
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        }
        // check for lowercase letter
        else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        }
        // check for digit
        else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
        // check for special character
        else {
            has_special_char = 1;
        }
    }

    // check overall password strength
    if ((length >= 8) && has_uppercase && has_lowercase && has_digit && has_special_char) {
        printf("Password is strong!");
    }
    else if ((length >= 6) && (has_uppercase || has_lowercase) && has_digit) {
        printf("Password is moderate!");
    }
    else {
        printf("Password is weak!");
    }

    return 0;
}