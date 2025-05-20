//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphanumeric character
int is_alphanum(char c) {
    return (isalnum(c) || isspace(c));
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Skip non-alphanumeric characters at start and end
        if (!is_alphanum(str[start])) {
            start++;
            continue;
        }
        if (!is_alphanum(str[end])) {
            end--;
            continue;
        }

        // Check if characters at start and end are the same
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

// Function to print the input string and its palindrome status
void print_result(char *str) {
    if (is_palindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
}

int main() {
    char str[101];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // Remove newline character

    print_result(str);

    return 0;
}