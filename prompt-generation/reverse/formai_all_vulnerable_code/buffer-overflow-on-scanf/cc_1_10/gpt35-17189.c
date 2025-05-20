//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This is a program that checks the strength of a password
 * based on various criteria: minimum length, uppercase
 * letters, lowercase letters, digits, and symbols.
 *
 * The program prompts the user to enter a password and
 * then provides feedback on the password's strength.
 * 
 * Author: [Your Name]
 * Date: [Current Date]
 */

int main() {
    char password[100]; // Maximum password length is 100 characters
    int length, upper, lower, digit, symbol;
    int i;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);
    upper = 0;
    lower = 0;
    digit = 0;
    symbol = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i]))
            upper++;
        else if (islower(password[i]))
            lower++;
        else if (isdigit(password[i]))
            digit++;
        else
            symbol++;
    }

    printf("\nPassword Strength Report:\n");
    printf("------------------------------\n");
    printf("Minimum Length:       %s\n", length >= 8 ? "PASS" : "FAIL");
    printf("Uppercase Letters:    %s\n", upper > 0 ? "PASS" : "FAIL");
    printf("Lowercase Letters:    %s\n", lower > 0 ? "PASS" : "FAIL");
    printf("Digits:               %s\n", digit > 0 ? "PASS" : "FAIL");
    printf("Symbols:              %s\n", symbol > 0 ? "PASS" : "FAIL");
    printf("------------------------------\n");

    return 0;
}