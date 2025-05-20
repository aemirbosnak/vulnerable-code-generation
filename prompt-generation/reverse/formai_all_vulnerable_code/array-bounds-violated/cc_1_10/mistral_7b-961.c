//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256

bool is_palindrome(const char* str, size_t length) {
    size_t i = 0;
    size_t j = length - 1;

    // Iterate through string while i < j
    while (i < j) {
        // Skip leading whitespaces
        while (isspace(str[i]) && i < length) i++;
        // Skip trailing whitespaces
        while (isspace(str[j]) && j > 0) j--;

        // If characters do not match, return false
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }

        i++;
        j--;
    }

    // If string length is odd, mid character must match itself
    if (length % 2 == 1) {
        if (tolower(str[length / 2]) != tolower(str[length / 2])) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX_STRING_LENGTH];
    size_t length;

    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);

    // Remove newline character from input
    length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    bool result = is_palindrome(str, length);

    if (result) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return EXIT_SUCCESS;
}