//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphanumeric character
int is_alnum(char c) {
    return (isalnum(c) || isspace(c) || ispunct(c) || isdigit(c) || isalpha(c));
}

// Function to remove whitespaces and punctuations from a string
void clean_string(char *str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (is_alnum(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }

    str[j] = '\0';
}

// Function to compare two strings in reverse order
int compare_strings_rev(char *str1, char *str2, int len) {
    int i;

    for (i = 0; i < len / 2; i++) {
        if (str1[i] != str2[len - i - 1]) {
            return 0;
        }
    }

    return (len % 2 == 0) ? str1[len / 2] == str2[len / 2] : 1;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);

    if (len <= 1) {
        return 1;
    }

    clean_string(str);

    if (len % 2 == 1) {
        return compare_strings_rev(str, str + len - 1, len);
    }

    return compare_strings_rev(str, str + len / 2, len);
}

// Function to test if a string is a palindrome and print the result
void test_palindrome(char *str) {
    int result = is_palindrome(str);

    if (result) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
}

int main() {
    char str[101];

    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", str);

    test_palindrome(str);

    return 0;
}