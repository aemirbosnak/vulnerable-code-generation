//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            special_character_count++;
        }
    }

    // Determine password strength based on number of character types
    int strength = 0;
    if (uppercase_count > 0) {
        strength++;
    }
    if (lowercase_count > 0) {
        strength++;
    }
    if (digit_count > 0) {
        strength++;
    }
    if (special_character_count > 0) {
        strength++;
    }

    printf("Password strength: ");
    switch (strength) {
        case 0:
            printf("Very Weak\n");
            break;
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
            printf("Very Strong\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return 0;
}