//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare variables
    char password[101];
    int strength = 0;
    int length = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int symbol = 0;

    // Get the password from the user
    printf("My darling, enter your password: ");
    scanf("%s", password);

    // Calculate the length of the password
    length = strlen(password);

    // Check if the password is too short
    if (length < 8) {
        printf("Oh, my sweet love, your password is too short! It must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower++;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit++;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++) {
        if (ispunct(password[i])) {
            symbol++;
        }
    }

    // Calculate the password strength
    if (upper > 0 && lower > 0 && digit > 0 && symbol > 0) {
        strength = 4;
    } else if (upper > 0 && lower > 0 && digit > 0) {
        strength = 3;
    } else if (upper > 0 && lower > 0) {
        strength = 2;
    } else if (lower > 0) {
        strength = 1;
    }

    // Print the password strength
    switch (strength) {
        case 4:
            printf("My dearest love, your password is as strong as our bond! It is unbreakable.\n");
            break;
        case 3:
            printf("My precious heart, your password is strong, but it could be stronger. Add a symbol to make it even more secure.\n");
            break;
        case 2:
            printf("My sweet darling, your password is okay, but it could be better. Add a digit to make it more secure.\n");
            break;
        case 1:
            printf("My lovely angel, your password is weak. Please choose a stronger password to protect your heart and our love.\n");
            break;
    }

    return 0;
}