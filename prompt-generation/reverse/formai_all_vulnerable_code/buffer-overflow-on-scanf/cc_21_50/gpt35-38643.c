//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[512]; // Maximum password length of 511 characters
    int length, i, lower_case, upper_case, special_char, digit;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Checking if the password meets the length requirement of 8 characters
    if (length < 8) {
        printf("Error: Password must be at least 8 characters long\n");
        exit(0);
    } else {
        strength++;
    }

    // Checking if the password contains at least one lowercase letter
    lower_case = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lower_case = 1;
            break;
        }
    }

    if (!lower_case) {
        printf("Error: Password must contain at least one lowercase letter\n");
        exit(0);
    } else {
        strength++;
    }

    // Checking if the password contains at least one uppercase letter
    upper_case = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper_case = 1;
            break;
        }
    }

    if (!upper_case) {
        printf("Error: Password must contain at least one uppercase letter\n");
        exit(0);
    } else {
        strength++;
    }

    // Checking if the password contains at least one special character
    special_char = 0;
    for (i = 0; i < length; i++) {
        if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))) {
            special_char = 1;
            break;
        }
    }

    if (!special_char) {
        printf("Error: Password must contain at least one special character\n");
        exit(0);
    } else {
        strength++;
    }

    // Checking if the password contains at least one digit
    digit = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            break;
        }
    }

    if (!digit) {
        printf("Error: Password must contain at least one digit\n");
        exit(0);
    } else {
        strength++;
    }

    // Calculating overall password strength based on the number of requirements met
    if (strength == 5) {
        printf("Password is extremely strong\n");
    } else if (strength == 4) {
        printf("Password is strong\n");
    } else if (strength == 3) {
        printf("Password is moderately strong\n");
    } else if (strength == 2) {
        printf("Password is weak\n");
    } else {
        printf("Password is very weak\n");
    }

    return 0;
}