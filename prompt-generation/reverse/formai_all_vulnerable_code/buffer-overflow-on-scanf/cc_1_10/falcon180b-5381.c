//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function to check if a character is a letter or a digit
int is_valid_char(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to count the number of uppercase letters, lowercase letters, digits, and special characters in a string
void count_chars(char* str, int* upper, int* lower, int* digit, int* special) {
    *upper = 0;
    *lower = 0;
    *digit = 0;
    *special = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            (*upper)++;
        } else if (islower(str[i])) {
            (*lower)++;
        } else if (isdigit(str[i])) {
            (*digit)++;
        } else {
            (*special)++;
        }
    }
}

// Function to check the strength of a password
char* check_strength(char* password) {
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    count_chars(password, &upper, &lower, &digit, &special);

    if (length < 8) {
        return "Too short";
    } else if (length >= 8 && length < 12) {
        if (upper >= 1 && lower >= 1 && digit >= 1) {
            return "Weak";
        } else {
            return "Very weak";
        }
    } else if (length >= 12 && length < 16) {
        if (upper >= 2 && lower >= 2 && digit >= 2) {
            return "Moderate";
        } else {
            return "Weak";
        }
    } else {
        if (upper >= 3 && lower >= 3 && digit >= 3 && special >= 1) {
            return "Strong";
        } else {
            return "Moderate";
        }
    }
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    char* result = check_strength(password);

    printf("Password strength: %s\n", result);

    return 0;
}