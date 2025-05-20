//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check for password strength
int check_password_strength(char *password) {
    int length = strlen(password);

    // variables to store different types of characters in the password
    int num_digits = 0, num_letters = 0, num_special = 0;

    // iterate through password character by character
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_digits++;
        } else if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
            num_letters++;
        } else {
            num_special++;
        }
    }

    // determine password strength based on character types
    if (length >= 8 && num_digits >= 1 && num_letters >= 1 && num_special >= 1) {
        return 3;
    } else if (length >= 8 && ((num_digits >= 1 && num_letters >= 1) || (num_letters >= 1 && num_special >= 1) || (num_digits >= 1 && num_special >= 1))) {
        return 2;
    } else if (length >= 6 && (num_digits >= 1 || num_letters >= 1)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength) {
        case 0:
            printf("Password is very weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is strong.\n");
            break;
        case 3:
            printf("Password is very strong.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}