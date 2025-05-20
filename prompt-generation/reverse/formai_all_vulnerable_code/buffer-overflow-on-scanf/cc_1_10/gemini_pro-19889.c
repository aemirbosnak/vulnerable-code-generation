//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string contains only digits
int is_all_digits(const char *s) {
    while (*s) {
        if (!isdigit(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

// Function to check if a string contains only letters
int is_all_letters(const char *s) {
    while (*s) {
        if (!isalpha(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric(const char *s) {
    while (*s) {
        if (!isalnum(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

// Function to check if a string contains only whitespace characters
int is_whitespace(const char *s) {
    while (*s) {
        if (!isspace(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

// Function to check if a string is a valid email address
int is_valid_email(const char *s) {
    int at_count = 0;
    int dot_count = 0;
    while (*s) {
        if (*s == '@') {
            at_count++;
        } else if (*s == '.') {
            dot_count++;
        }
        s++;
    }
    return (at_count == 1) && (dot_count >= 1);
}

// Function to check if a string is a valid URL
int is_valid_url(const char *s) {
    if (strncmp(s, "http://", 7) == 0) {
        return 1;
    } else if (strncmp(s, "https://", 8) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Check the type of the input string
    if (is_all_digits(input)) {
        printf("The input string is a number.\n");
    } else if (is_all_letters(input)) {
        printf("The input string is a word.\n");
    } else if (is_alphanumeric(input)) {
        printf("The input string is alphanumeric.\n");
    } else if (is_whitespace(input)) {
        printf("The input string is whitespace.\n");
    } else if (is_valid_email(input)) {
        printf("The input string is a valid email address.\n");
    } else if (is_valid_url(input)) {
        printf("The input string is a valid URL.\n");
    } else {
        printf("The input string is invalid.\n");
    }

    return 0;
}