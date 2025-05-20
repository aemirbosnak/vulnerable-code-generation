//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int is_alnum(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to reverse a string
void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to check if a string is palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    if (len <= 1) {
        return 1;
    }

    if (is_alnum(str[0]) && is_alnum(str[len - 1])) {
        if (tolower(str[0]) != tolower(str[len - 1])) {
            return 0;
        }
        reverse_string(str, 0, len - 2);
        return is_palindrome(str);
    }

    return 0;
}

int main() {
    char input[1024];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, sizeof(input), stdin);

    input[strlen(input) - 1] = '\0'; // Remove newline character

    if (is_palindrome(input)) {
        printf("The string '%s' is a palindrome.\n", input);
    } else {
        printf("The string '%s' is not a palindrome.\n", input);
    }

    return 0;
}