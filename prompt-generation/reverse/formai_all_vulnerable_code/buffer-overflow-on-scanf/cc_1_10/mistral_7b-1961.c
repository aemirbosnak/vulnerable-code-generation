//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string using dynamic memory allocation
char* reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = (char*) malloc(len * sizeof(char) + 1);
    int i = 0, j = len;

    // Copying reversed string
    while (i < len) {
        reversed[i] = str[j];
        i++;
        j--;
    }

    // Adding null terminator
    reversed[len] = '\0';
    return reversed;
}

// Function to check if two strings are identical
int are_strings_identical(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);

    // Check if lengths are same
    if (len1 != len2) return 0;

    // Check character by character
    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[len1 - i - 1])
            return 0;

    return 1;
}

// Function to check if a given string is a palindrome
int is_palindrome(char* str) {
    // Check base cases
    if (strlen(str) <= 1) return 1;
    if (strlen(str) % 2 == 0) { // Even length
        char* left_half = strtok(str, ""); // Tokenize at each character
        char* right_half = reverse_string(str + (strlen(str) / 2));
        free(left_half);
        if (!are_strings_identical(left_half, right_half)) {
            free(right_half);
            return 0;
        }
        free(right_half);
    } else { // Odd length
        char c = *str;
        char* right_half = reverse_string(str + (strlen(str) / 2) + 1);
        if (!are_strings_identical(str + (strlen(str) + 1) / 2, right_half)) {
            free(right_half);
            return 0;
        }
        free(right_half);
        if (*str != c) return 0;
    }

    return 1;
}

int main() {
    char input[101];
    printf("Enter a string: ");
    scanf("%s", input);

    if (is_palindrome(input))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}