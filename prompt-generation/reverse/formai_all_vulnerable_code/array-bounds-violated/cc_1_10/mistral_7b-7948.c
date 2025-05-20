//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 101

int is_palindrome(char *str, int start, int end);
void to_lower(char *str, int length);
void reverse_string(char *str, int start, int end);

int main() {
    char input[MAX_LENGTH];
    int length, i, result;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input string
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    length = strlen(input);

    // Check if the string is palindrome
    result = is_palindrome(input, 0, length - 1);

    if (result) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}

int is_palindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (tolower(str[start]) != tolower(str[end])) {
        return 0;
    }

    reverse_string(str, start + 1, end);

    return is_palindrome(str, start + 1, end - 1);
}

void to_lower(char *str, int length) {
    int i;

    for (i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

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