//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special_char(char c) {
    return!is_letter(c) &&!is_digit(c);
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_letters = 0;
    int has_digits = 0;
    int has_special_chars = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (is_letter(c)) {
            has_letters = 1;
        } else if (is_digit(c)) {
            has_digits = 1;
        } else if (is_special_char(c)) {
            has_special_chars = 1;
        }
    }

    if (length < 8) {
        return 1; // Weak
    } else if (length < 12 ||!has_letters ||!has_digits) {
        return 2; // Moderate
    } else if (length < 16 ||!has_special_chars) {
        return 3; // Strong
    } else {
        return 4; // Very strong
    }
}

// Function to generate a random password
void generate_password(char *password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter the desired password length (between 8 and 32): ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    generate_password(password, length);
    printf("Generated password: %s\n", password);

    int strength = check_password_strength(password);
    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very strong\n");
            break;
    }

    return 0;
}