//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE 1
#define MIN_UPPER_CASE 1
#define MIN_NUMBERS 1
#define MIN_SPECIAL_CHARS 1

int check_password_strength(char password[MAX_PASSWORD_LENGTH]) {
    int length = strlen(password);
    int lower_case_count = 0;
    int upper_case_count = 0;
    int numbers_count = 0;
    int special_chars_count = 0;

    // Check for minimum length
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 0;
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i]) && islower(password[i])) {
            lower_case_count++;
        }
    }
    if (lower_case_count < MIN_LOWER_CASE) {
        printf("Password must contain at least %d lowercase letters.\n", MIN_LOWER_CASE);
        return 0;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i]) && isupper(password[i])) {
            upper_case_count++;
        }
    }
    if (upper_case_count < MIN_UPPER_CASE) {
        printf("Password must contain at least %d uppercase letters.\n", MIN_UPPER_CASE);
        return 0;
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers_count++;
        }
    }
    if (numbers_count < MIN_NUMBERS) {
        printf("Password must contain at least %d numbers.\n", MIN_NUMBERS);
        return 0;
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_chars_count++;
        }
    }
    if (special_chars_count < MIN_SPECIAL_CHARS) {
        printf("Password must contain at least %d special characters.\n", MIN_SPECIAL_CHARS);
        return 0;
    }

    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int result = check_password_strength(password);

    return 0;
}