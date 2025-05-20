//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
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
    if (at_count == 1 && dot_count >= 1) {
        return 1;
    }
    return 0;
}

// Function to check if a string is a valid URL
int is_url(const char *str) {
    if (strncmp(str, "http://", 7) == 0 || strncmp(str, "https://", 8) == 0) {
        return 1;
    }
    return 0;
}

// Function to sanitize a string
char *sanitize_string(const char *str) {
    // Allocate memory for the sanitized string
    char *sanitized_str = malloc(strlen(str) + 1);

    // Copy the sanitized string to the allocated memory
    strcpy(sanitized_str, str);

    // Replace all non-alphanumeric characters with underscores
    for (int i = 0; sanitized_str[i] != '\0'; i++) {
        if (!isalnum(sanitized_str[i])) {
            sanitized_str[i] = '_';
        }
    }

    // Return the sanitized string
    return sanitized_str;
}

int main() {
    // Get the input string from the user
    char input_str[100];
    printf("Enter a string: ");
    scanf("%s", input_str);

    // Check if the input string is a number
    if (is_number(input_str)) {
        printf("The input string is a number.\n");
    }

    // Check if the input string is an email address
    else if (is_email(input_str)) {
        printf("The input string is an email address.\n");
    }

    // Check if the input string is a URL
    else if (is_url(input_str)) {
        printf("The input string is a URL.\n");
    }

    // Otherwise, sanitize the input string
    else {
        char *sanitized_str = sanitize_string(input_str);
        printf("The sanitized string is: %s\n", sanitized_str);
        free(sanitized_str);
    }

    return 0;
}