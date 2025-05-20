//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100
#define USER_LEN 20

// Function to check if a character is a digit
int isdigit_checker(char c) {
    return (isdigit(c) != 0);
}

// Function to check if a character is an alphabet (uppercase or lowercase)
int isalpha_checker(char c) {
    return (isalpha(c) != 0);
}

// Function to check if a character is a special character
int isspecial_checker(char c) {
    return (strchr("!@#$%^&*()_+-=[]{};:<>,.?/~`|", c) != NULL);
}

// Function to check if a password meets the strength criteria
int check_password_strength(char *password, char *username) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int consecutive_identical = 0;

    if (length < 8) {
        return 0;
    }

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit_checker(password[i])) {
            has_digit = 1;
        } else if (isspecial_checker(password[i])) {
            has_special = 1;
        }

        if (consecutive_identical > 2 && password[i] == password[i-1]) {
            return 0;
        }

        if (strchr(username, password[i]) != NULL) {
            return 0;
        }

        if (i > 0 && password[i] == password[i-1]) {
            consecutive_identical++;
        } else {
            consecutive_identical = 0;
        }
    }

    if (!has_upper || !has_lower || !has_digit || !has_special) {
        return 0;
    }

    return 1;
}

int main() {
    char username[USER_LEN], password[MAX_LEN];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (check_password_strength(password, username)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}