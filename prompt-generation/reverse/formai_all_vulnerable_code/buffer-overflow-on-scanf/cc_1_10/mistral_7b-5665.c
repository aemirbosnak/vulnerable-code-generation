//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1001

// Function to check if a string is palindrome
int is_palindrome(char *str, int length) {
    int start = 0;
    int end = length - 1;

    // Move pointers to the middle of the string if it's an odd-length palindrome
    if (length % 2 != 0) {
        start++;
    }

    // Compare characters at start and end, move pointers inward
    while (start < end) {
        // Ignore non-alphanumeric characters
        if (!isalnum(str[start])) {
            start++;
            continue;
        }
        if (!isalnum(str[end])) {
            end--;
            continue;
        }

        // Case-insensitive comparison
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

// Function to print the given string in reverse
void print_reverse(char *str) {
    int length = strlen(str);
    int i;

    printf("Reversed version of given string: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char input_string[MAX_LENGTH];

    // Get input string from user
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input_string);

    // Calculate length of the string
    int length = strlen(input_string);

    // Check if the string is a palindrome
    if (is_palindrome(input_string, length)) {
        printf("%s is a palindrome!\n", input_string);
    } else {
        printf("%s is not a palindrome.\n", input_string);
        printf("Reversed version of given string: ");
        print_reverse(input_string);
    }

    return 0;
}