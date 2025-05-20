//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, uppercase_count, lowercase_count, digit_count, special_char_count;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase letters
    uppercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase letters
    lowercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    digit_count = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    special_char_count = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_char_count++;
        }
    }

    printf("Password strength: ");

    // Display the password strength based on the number of characters
    if (length < 8) {
        printf("Weak\n");
    } else if (length >= 8 && length < 12) {
        printf("Moderate\n");
    } else if (length >= 12) {
        printf("Strong\n");
    }

    // Display the number of uppercase letters, lowercase letters, digits, and special characters in the password
    printf("\n");
    printf("Uppercase letters: %d\n", uppercase_count);
    printf("Lowercase letters: %d\n", lowercase_count);
    printf("Digits: %d\n", digit_count);
    printf("Special characters: %d\n", special_char_count);

    return 0;
}