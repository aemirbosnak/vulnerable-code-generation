//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[25];
    int length, upper = 0, lower = 0, digit = 0, special = 0, strength = 0;

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    length = strlen(password);
    password[length - 1] = '\0'; //removing newline character

    //Checking Password for strength
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
        }
        else {
            special = 1;
        }
    }

    if (upper && lower && digit && special) {
        strength = 4;
    }
    else if ((upper && lower && digit) || (lower && digit && special) || (digit && special && upper) || (special && upper && lower)) {
        strength = 3;
    }
    else if ((upper && lower) || (lower && digit) || (digit && special) || (special && upper)) {
        strength = 2;
    }
    else {
        strength = 1;
    }

    //Displaying the strength of password
    switch (strength) {
        case 1:
            printf("\nYour password is very weak.");
            printf("\nAdd some upper-case, lower-case, digits, and special characters to strengthen your password.");
            break;
        case 2:
            printf("\nYour password is weak.");
            printf("\nAdd some upper-case, lower-case, digits, and special characters to strengthen your password.");
            break;
        case 3:
            printf("\nYour password is good.");
            printf("\nYou can add some more special characters to make your password stronger.");
            break;
        case 4:
            printf("\nYour password is very strong.");
            printf("\nKeep up the good work!");
            break;
        default:
            printf("\nInvalid Password.");
    }

    return 0;
}