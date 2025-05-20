//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to check if a string contains only digits
int is_digits(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Define a function to check if a string contains only letters
int is_letters(const char *str) {
    while (*str) {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Define a function to check if a string contains only alphanumeric characters
int is_alphanumeric(const char *str) {
    while (*str) {
        if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Define a function to check if a string is a valid email address
int is_email(const char *str) {
    int at_count = 0;
    int dot_count = 0;
    while (*str) {
        if (*str == '@') {
            at_count++;
        } else if (*str == '.') {
            dot_count++;
        }
        str++;
    }
    return at_count == 1 && dot_count >= 1;
}

// Define a function to check if a string is a valid URL
int is_url(const char *str) {
    if (strncmp(str, "http://", 7) == 0 || strncmp(str, "https://", 8) == 0) {
        return 1;
    }
    return 0;
}

// Define a function to check if a string is a valid phone number
int is_phone(const char *str) {
    int dash_count = 0;
    int digit_count = 0;
    while (*str) {
        if (*str == '-') {
            dash_count++;
        } else if (*str >= '0' && *str <= '9') {
            digit_count++;
        }
        str++;
    }
    return dash_count == 2 && digit_count == 10;
}

// Define a function to check if a string is a valid date
int is_date(const char *str) {
    int slash_count = 0;
    int digit_count = 0;
    while (*str) {
        if (*str == '/') {
            slash_count++;
        } else if (*str >= '0' && *str <= '9') {
            digit_count++;
        }
        str++;
    }
    return slash_count == 2 && digit_count == 8;
}

// Define a function to check if a string is a valid time
int is_time(const char *str) {
    int colon_count = 0;
    int digit_count = 0;
    while (*str) {
        if (*str == ':') {
            colon_count++;
        } else if (*str >= '0' && *str <= '9') {
            digit_count++;
        }
        str++;
    }
    return colon_count == 1 && digit_count == 4;
}

// Define a function to check if a string is a valid credit card number
int is_credit_card(const char *str) {
    int dash_count = 0;
    int digit_count = 0;
    while (*str) {
        if (*str == '-') {
            dash_count++;
        } else if (*str >= '0' && *str <= '9') {
            digit_count++;
        }
        str++;
    }
    return dash_count == 3 && digit_count == 16;
}

// Define a function to check if a string is a valid social security number
int is_ssn(const char *str) {
    int dash_count = 0;
    int digit_count = 0;
    while (*str) {
        if (*str == '-') {
            dash_count++;
        } else if (*str >= '0' && *str <= '9') {
            digit_count++;
        }
        str++;
    }
    return dash_count == 2 && digit_count == 9;
}

// Define a main function to test the input sanitizers
int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (is_digits(input)) {
        printf("The input is a number.\n");
    } else if (is_letters(input)) {
        printf("The input is a string of letters.\n");
    } else if (is_alphanumeric(input)) {
        printf("The input is a string of alphanumeric characters.\n");
    } else if (is_email(input)) {
        printf("The input is a valid email address.\n");
    } else if (is_url(input)) {
        printf("The input is a valid URL.\n");
    } else if (is_phone(input)) {
        printf("The input is a valid phone number.\n");
    } else if (is_date(input)) {
        printf("The input is a valid date.\n");
    } else if (is_time(input)) {
        printf("The input is a valid time.\n");
    } else if (is_credit_card(input)) {
        printf("The input is a valid credit card number.\n");
    } else if (is_ssn(input)) {
        printf("The input is a valid social security number.\n");
    } else {
        printf("The input is invalid.\n");
    }

    return 0;
}