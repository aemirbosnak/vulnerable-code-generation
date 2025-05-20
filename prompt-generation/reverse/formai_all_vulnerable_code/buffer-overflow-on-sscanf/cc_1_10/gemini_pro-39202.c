//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function checks if a string contains only alphanumeric characters.
int is_alphanumeric(const char *str) {
    while (*str) {
        if (!isalnum(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// This function checks if a string is a valid email address.
int is_valid_email(const char *str) {
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

// This function checks if a string is a valid phone number.
int is_valid_phone_number(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '-') {
            return 0;
        }
        str++;
    }
    return 1;
}

// This function checks if a string is a valid date.
int is_valid_date(const char *str) {
    int day, month, year;
    if (sscanf(str, "%d-%d-%d", &day, &month, &year) != 3) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (year < 1000 || year > 9999) {
        return 0;
    }
    return 1;
}

int main() {
    char input[100];
    int choice;

    printf("Welcome to the C User Input Sanitizer!\n");
    printf("Please select an option:\n");
    printf("1. Check if a string is alphanumeric.\n");
    printf("2. Check if a string is a valid email address.\n");
    printf("3. Check if a string is a valid phone number.\n");
    printf("4. Check if a string is a valid date.\n");
    printf("5. Exit.\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a string: ");
            scanf("%s", input);
            if (is_alphanumeric(input)) {
                printf("The string is alphanumeric.\n");
            } else {
                printf("The string is not alphanumeric.\n");
            }
            break;
        case 2:
            printf("Enter an email address: ");
            scanf("%s", input);
            if (is_valid_email(input)) {
                printf("The email address is valid.\n");
            } else {
                printf("The email address is not valid.\n");
            }
            break;
        case 3:
            printf("Enter a phone number: ");
            scanf("%s", input);
            if (is_valid_phone_number(input)) {
                printf("The phone number is valid.\n");
            } else {
                printf("The phone number is not valid.\n");
            }
            break;
        case 4:
            printf("Enter a date: ");
            scanf("%s", input);
            if (is_valid_date(input)) {
                printf("The date is valid.\n");
            } else {
                printf("The date is not valid.\n");
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}