//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digit(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

// Function to check if a string contains only valid characters
int is_valid(char *str) {
    while (*str) {
        if (*str < 'a' || *str > 'z')
            if (*str < 'A' || *str > 'Z')
                if (*str < '0' || *str > '9')
                    return 0;
        str++;
    }
    return 1;
}

// Function to sanitize a string
char *sanitize(char *str) {
    char *new_str = malloc(strlen(str) + 1); // Allocate memory for the new string
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (is_valid(&str[i])) {
            new_str[j++] = str[i];
        }
        i++;
    }
    new_str[j] = '\0'; // Null-terminate the new string
    return new_str;
}

int main() {
    char *str = malloc(100); // Allocate memory for the input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the input string contains only digits
    if (is_digit(str)) {
        printf("The input string is a number.\n");
    } else {
        // Sanitize the input string
        char *new_str = sanitize(str);
        printf("The sanitized string is: %s\n", new_str);
        free(new_str); // Deallocate memory for the sanitized string
    }

    free(str); // Deallocate memory for the input string
    return 0;
}