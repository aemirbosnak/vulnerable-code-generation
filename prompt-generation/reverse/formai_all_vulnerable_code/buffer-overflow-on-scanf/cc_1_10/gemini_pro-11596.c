//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: retro
// "Sanitation Station: Retro Edition"
// by The Commodore 64 Club

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char *strip_control_chars(char *input);
char *strip_non_printable_chars(char *input);
char *strip_whitespace(char *input);
char *validate_email(char *input);
char *validate_phone_number(char *input);
char *validate_credit_card_number(char *input);

// Main function
int main() {
    // Initialize variables
    char input[100];
    char *sanitized_input;

    // Prompt the user for input
    printf("Welcome to the Sanitation Station, Retro Edition!\n");
    printf("Enter your input: ");
    scanf("%s", input);

    // Strip control characters
    sanitized_input = strip_control_chars(input);

    // Strip non-printable characters
    sanitized_input = strip_non_printable_chars(sanitized_input);

    // Strip whitespace
    sanitized_input = strip_whitespace(sanitized_input);

    // Validate the input
    if (validate_email(sanitized_input) != NULL) {
        printf("Your input is a valid email address.\n");
    } else if (validate_phone_number(sanitized_input) != NULL) {
        printf("Your input is a valid phone number.\n");
    } else if (validate_credit_card_number(sanitized_input) != NULL) {
        printf("Your input is a valid credit card number.\n");
    } else {
        printf("Your input is not a valid email address, phone number, or credit card number.\n");
    }

    return 0;
}

// Function to strip control characters
char *strip_control_chars(char *input) {
    char *sanitized_input = malloc(strlen(input) + 1);
    int i = 0;
    int j = 0;

    while (input[i] != '\0') {
        if (input[i] < 32 || input[i] > 126) {
            i++;
        } else {
            sanitized_input[j++] = input[i++];
        }
    }

    sanitized_input[j] = '\0';
    return sanitized_input;
}

// Function to strip non-printable characters
char *strip_non_printable_chars(char *input) {
    char *sanitized_input = malloc(strlen(input) + 1);
    int i = 0;
    int j = 0;

    while (input[i] != '\0') {
        if (isprint(input[i])) {
            sanitized_input[j++] = input[i++];
        } else {
            i++;
        }
    }

    sanitized_input[j] = '\0';
    return sanitized_input;
}

// Function to strip whitespace
char *strip_whitespace(char *input) {
    char *sanitized_input = malloc(strlen(input) + 1);
    int i = 0;
    int j = 0;

    while (input[i] != '\0') {
        if (!isspace(input[i])) {
            sanitized_input[j++] = input[i++];
        } else {
            i++;
        }
    }

    sanitized_input[j] = '\0';
    return sanitized_input;
}

// Function to validate an email address
char *validate_email(char *input) {
    int i = 0;
    int at_count = 0;
    int dot_count = 0;

    while (input[i] != '\0') {
        if (input[i] == '@') {
            at_count++;
        } else if (input[i] == '.') {
            dot_count++;
        }

        i++;
    }

    if (at_count == 1 && dot_count > 0) {
        return input;
    } else {
        return NULL;
    }
}

// Function to validate a phone number
char *validate_phone_number(char *input) {
    int i = 0;
    int digit_count = 0;

    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            digit_count++;
        }

        i++;
    }

    if (digit_count == 10) {
        return input;
    } else {
        return NULL;
    }
}

// Function to validate a credit card number
char *validate_credit_card_number(char *input) {
    int i = 0;
    int digit_count = 0;
    int sum = 0;

    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            digit_count++;
            sum += input[i] - '0';
        }

        i++;
    }

    if (digit_count == 16 && sum % 10 == 0) {
        return input;
    } else {
        return NULL;
    }
}