//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

// Function to check if the given character is an alphabet
int isAlphabet(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else if (ch >= 'A' && ch <= 'Z')
        return 1;
    else
        return 0;
}

// Function to check if the given character is a digit
int isDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

// Function to check if the given character is a special character
int isSpecialChar(char ch) {
    if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '*' || ch == '?')
        return 1;
    else
        return 0;
}

// Function to check if the given password is strong enough
int isStrongPassword(char password[MAX_PASSWORD_LENGTH]) {
    int hasAlphabet = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH)
        return 0;

    // Check for alphabet
    for (int i = 0; i < length; i++) {
        if (isAlphabet(password[i]))
            hasAlphabet = 1;
    }

    // Check for digit
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i]))
            hasDigit = 1;
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (isSpecialChar(password[i]))
            hasSpecialChar = 1;
    }

    // If password contains at least one alphabet, one digit and one special character, it is strong
    if (hasAlphabet && hasDigit && hasSpecialChar)
        return 1;
    else
        return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is strong
    if (isStrongPassword(password))
        printf("Your password is strong.\n");
    else
        printf("Your password is weak. Please make it stronger.\n");

    return 0;
}