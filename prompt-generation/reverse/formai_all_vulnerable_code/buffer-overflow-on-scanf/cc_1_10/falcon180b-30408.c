//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter
int isLetter(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a character is a number
int isNumber(char c) {
    if (isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a character is a special character
int isSpecial(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check password strength
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int hasLetter = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    // Check if password contains at least one letter, one number, and one special character
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
        } else if (isNumber(password[i])) {
            hasNumber = 1;
        } else if (isSpecial(password[i])) {
            hasSpecial = 1;
        }
    }

    if (length >= 8 && hasLetter && hasNumber && hasSpecial) {
        return 1; // Strong password
    } else {
        return 0; // Weak password
    }
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    if (strength == 1) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak!\n");
    }

    return 0;
}