//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only letters
int is_letters(char *str) {
    while (*str) {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string is a valid email address
int is_email(char *str) {
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
    return (at_count == 1 && dot_count >= 1);
}

// Function to check if a string is a valid IP address
int is_ip(char *str) {
    int octet_count = 0;
    int dot_count = 0;
    while (*str) {
        if (*str == '.') {
            dot_count++;
            octet_count = 0;
        } else if (*str < '0' || *str > '9') {
            return 0;
        } else {
            octet_count++;
        }
        str++;
    }
    return (dot_count == 3 && octet_count <= 3);
}

// Function to check if a string is a valid date
int is_date(char *str) {
    int slash_count = 0;
    int day_count = 0;
    int month_count = 0;
    int year_count = 0;
    while (*str) {
        if (*str == '/') {
            slash_count++;
            day_count = 0;
            month_count = 0;
            year_count = 0;
        } else if (*str < '0' || *str > '9') {
            return 0;
        } else if (slash_count == 0) {
            day_count++;
        } else if (slash_count == 1) {
            month_count++;
        } else if (slash_count == 2) {
            year_count++;
        }
        str++;
    }
    return (slash_count == 2 && day_count <= 2 && month_count <= 2 && year_count <= 4);
}

// Main function
int main() {
    char str[100];
    int choice;

    // Get the user's choice
    printf("Enter your choice:\n");
    printf("1. Check if a string contains only digits\n");
    printf("2. Check if a string contains only letters\n");
    printf("3. Check if a string is a valid email address\n");
    printf("4. Check if a string is a valid IP address\n");
    printf("5. Check if a string is a valid date\n");
    scanf("%d", &choice);

    // Get the user's input
    printf("Enter a string:\n");
    scanf("%s", str);

    // Check the user's input
    switch (choice) {
        case 1:
            if (is_digits(str)) {
                printf("The string contains only digits.\n");
            } else {
                printf("The string does not contain only digits.\n");
            }
            break;
        case 2:
            if (is_letters(str)) {
                printf("The string contains only letters.\n");
            } else {
                printf("The string does not contain only letters.\n");
            }
            break;
        case 3:
            if (is_email(str)) {
                printf("The string is a valid email address.\n");
            } else {
                printf("The string is not a valid email address.\n");
            }
            break;
        case 4:
            if (is_ip(str)) {
                printf("The string is a valid IP address.\n");
            } else {
                printf("The string is not a valid IP address.\n");
            }
            break;
        case 5:
            if (is_date(str)) {
                printf("The string is a valid date.\n");
            } else {
                printf("The string is not a valid date.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}