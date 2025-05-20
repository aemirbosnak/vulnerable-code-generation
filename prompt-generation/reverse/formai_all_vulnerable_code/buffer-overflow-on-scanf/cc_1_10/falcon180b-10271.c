//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20 // Maximum password length
#define MIN_LENGTH 8 // Minimum password length
#define MIN_LOWER 1 // Minimum number of lowercase letters
#define MIN_UPPER 1 // Minimum number of uppercase letters
#define MIN_NUM 1 // Minimum number of numbers
#define MIN_SPECIAL 1 // Minimum number of special characters

int is_lower(char c);
int is_upper(char c);
int is_number(char c);
int is_special(char c);

int main() {
    char password[MAX_LENGTH];
    int length, lower, upper, number, special;
    srand(time(NULL)); // Initialize random seed

    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Get password length
    length = strlen(password);

    // Check if password meets minimum length requirement
    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    // Initialize counters
    lower = 0;
    upper = 0;
    number = 0;
    special = 0;

    // Loop through each character in the password
    for (int i = 0; i < length; i++) {
        if (is_lower(password[i])) {
            lower++;
        } else if (is_upper(password[i])) {
            upper++;
        } else if (is_number(password[i])) {
            number++;
        } else if (is_special(password[i])) {
            special++;
        }
    }

    // Check if password meets complexity requirements
    if (lower < MIN_LOWER) {
        printf("Password must contain at least %d lowercase letters.\n", MIN_LOWER);
        return 1;
    }

    if (upper < MIN_UPPER) {
        printf("Password must contain at least %d uppercase letters.\n", MIN_UPPER);
        return 1;
    }

    if (number < MIN_NUM) {
        printf("Password must contain at least %d numbers.\n", MIN_NUM);
        return 1;
    }

    if (special < MIN_SPECIAL) {
        printf("Password must contain at least %d special characters.\n", MIN_SPECIAL);
        return 1;
    }

    // Print password strength
    printf("Password strength: ");
    if (length < 12) {
        printf("Weak\n");
    } else if (length < 16) {
        printf("Medium\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_number(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '^' || c == '~');
}