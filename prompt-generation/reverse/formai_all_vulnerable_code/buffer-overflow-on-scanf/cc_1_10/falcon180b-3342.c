//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function to check if a character is a letter
int is_letter(char c) {
    if (isalpha(c)) {
        return 1;
    }
    return 0;
}

// Function to check if a character is a number
int is_number(char c) {
    if (isdigit(c)) {
        return 1;
    }
    return 0;
}

// Function to check if a character is a special character
int is_special(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?') {
        return 1;
    }
    return 0;
}

// Function to check password strength
int check_password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (is_number(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (is_special(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Determine password strength
    if (length < 8) {
        return 1; // Weak
    } else if (length < 12 ||!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        return 2; // Moderate
    } else {
        return 3; // Strong
    }
}

int main() {
    char password[MAX_LENGTH];

    // Get password from user
    printf("Enter thy password: ");
    scanf("%s", password);

    // Check password strength
    int strength = check_password_strength(password);

    switch (strength) {
        case 1:
            printf("Thy password is weak!\n");
            break;
        case 2:
            printf("Thy password is moderate.\n");
            break;
        case 3:
            printf("Thy password is strong!\n");
            break;
    }

    return 0;
}