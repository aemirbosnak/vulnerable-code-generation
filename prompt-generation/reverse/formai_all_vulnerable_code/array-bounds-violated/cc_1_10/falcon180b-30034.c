//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Alan Turing
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to check if a given string is a palindrome
int is_palindrome(char* str) {
    int length = strlen(str);
    if (length <= 1) {
        return 1;
    }

    // Convert string to lowercase and remove non-alphanumeric characters
    char cleaned_str[MAX_LENGTH];
    int cleaned_length = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            cleaned_str[cleaned_length] = tolower(str[i]);
            cleaned_length++;
        }
    }

    // Check if cleaned string is equal to its reverse
    for (int i = 0; i < cleaned_length / 2; i++) {
        if (cleaned_str[i]!= cleaned_str[cleaned_length - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input_str, MAX_LENGTH, stdin);

    // Remove newline character from input string
    int length = strlen(input_str);
    if (input_str[length - 1] == '\n') {
        input_str[length - 1] = '\0';
        length--;
    }

    if (is_palindrome(input_str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}