//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphanumeric character
int is_alnum(char c) {
    return (isalnum(c) || isspace(c));
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Skip non-alphanumeric characters on both sides
        if (!is_alnum(str[start])) {
            start++;
            continue;
        }
        if (!is_alnum(str[end])) {
            end--;
            continue;
        }

        // Check for character equality
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

// Function to print the result of palindrome check
void print_result(char *str, int result) {
    if (result) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
}

int main() {
    char input[101];

    printf("Enter a string to check for palindrome: ");
    scanf("%s", input);

    // Call the is_palindrome function and print the result
    int result = is_palindrome(input);
    print_result(input, result);

    return 0;
}