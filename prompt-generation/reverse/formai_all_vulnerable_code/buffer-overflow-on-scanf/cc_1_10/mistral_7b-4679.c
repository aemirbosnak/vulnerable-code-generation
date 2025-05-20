//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to reverse a string
void reverse_string(char *str, int start, int end) {
    if (start >= end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse_string(str, start + 1, end - 1);
}

// Function to check if a given string is palindrome or not
int is_palindrome(char *str) {
    int len = strlen(str);

    // Base case: empty string or single character string is palindrome
    if (len <= 1)
        return 1;

    // Reverse the string
    reverse_string(str, 0, len - 1);

    // Compare the original string and reversed string character by character
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is palindrome or not
    if (is_palindrome(str))
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    return 0;
}