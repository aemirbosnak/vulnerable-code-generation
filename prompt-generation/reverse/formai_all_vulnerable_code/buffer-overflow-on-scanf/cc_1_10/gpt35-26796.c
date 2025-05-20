//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
// A C program to check password strength in a modular style

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to check if the password is strong or not
int check_password_strength(char *password) {
    int i, letter_count = 0, digit_count = 0, special_count = 0;
    int len = strlen(password);

    // Check length of password
    if (len < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    // Check if password contains letters, digits and special characters
    for (i = 0; i < len; i++) {
        if (isalpha(password[i])) {
            letter_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else {
            special_count++;
        }
    }

    // Check if password contains at least one letter, digit and special character
    if (letter_count == 0 || digit_count == 0 || special_count == 0) {
        printf("Password should contain at least one letter, digit and special character.\n");
        return 0;
    }

    // Password is strong
    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[50];

    // Input password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    check_password_strength(password);

    return 0;
}