//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only letters
int is_letters(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid email address
int is_email(const char *str) {
    int at_count = 0;
    int dot_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@') {
            at_count++;
        } else if (str[i] == '.') {
            dot_count++;
        }
    }
    return (at_count == 1 && dot_count >= 1);
}

// Function to check if a string is a valid phone number
int is_phone_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '(' && str[i] != ')') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid date
int is_date(const char *str) {
    int slash_count = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/') {
            slash_count++;
        } else if (isdigit(str[i])) {
            if (slash_count == 0) {
                day *= 10;
                day += str[i] - '0';
            } else if (slash_count == 1) {
                month *= 10;
                month += str[i] - '0';
            } else if (slash_count == 2) {
                year *= 10;
                year += str[i] - '0';
            }
        }
    }
    return (slash_count == 2 && day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1900 && year <= 2100);
}

// Function to sanitize a string by removing all non-alphanumeric characters
char *sanitize_string(char *str) {
    int new_length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[new_length++] = str[i];
        }
    }
    str[new_length] = '\0';
    return str;
}

// Function to test the input sanitization functions
int main() {
    char input[100];

    printf("Enter a string to check if it contains only digits: ");
    scanf("%s", input);
    if (is_digits(input)) {
        printf("The string '%s' contains only digits.\n", input);
    } else {
        printf("The string '%s' does not contain only digits.\n", input);
    }

    printf("\nEnter a string to check if it contains only letters: ");
    scanf("%s", input);
    if (is_letters(input)) {
        printf("The string '%s' contains only letters.\n", input);
    } else {
        printf("The string '%s' does not contain only letters.\n", input);
    }

    printf("\nEnter a string to check if it contains only alphanumeric characters: ");
    scanf("%s", input);
    if (is_alphanumeric(input)) {
        printf("The string '%s' contains only alphanumeric characters.\n", input);
    } else {
        printf("The string '%s' does not contain only alphanumeric characters.\n", input);
    }

    printf("\nEnter a string to check if it is a valid email address: ");
    scanf("%s", input);
    if (is_email(input)) {
        printf("The string '%s' is a valid email address.\n", input);
    } else {
        printf("The string '%s' is not a valid email address.\n", input);
    }

    printf("\nEnter a string to check if it is a valid phone number: ");
    scanf("%s", input);
    if (is_phone_number(input)) {
        printf("The string '%s' is a valid phone number.\n", input);
    } else {
        printf("The string '%s' is not a valid phone number.\n", input);
    }

    printf("\nEnter a string to check if it is a valid date: ");
    scanf("%s", input);
    if (is_date(input)) {
        printf("The string '%s' is a valid date.\n", input);
    } else {
        printf("The string '%s' is not a valid date.\n", input);
    }

    printf("\nEnter a string to sanitize: ");
    scanf("%s", input);
    printf("The sanitized string is '%s'.\n", sanitize_string(input));

    return 0;
}