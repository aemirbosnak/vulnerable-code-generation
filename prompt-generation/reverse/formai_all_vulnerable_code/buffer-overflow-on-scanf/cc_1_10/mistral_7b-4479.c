//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to check if a given string is a palindrome
int is_palindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to check if a given string is a palindrome recursively
int recursive_is_palindrome(char str[], int index) {
    if (index >= strlen(str) / 2) {
        return 1;
    }
    if (str[index] != str[strlen(str) - index - 1]) {
        return 0;
    }
    return recursive_is_palindrome(str, index + 1);
}

// Function to check if a given character is valid alphanumeric or not
int is_valid_char(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// Function to remove spaces from a given string
void remove_spaces(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (is_valid_char(str[i])) {
            str[j] = str[i];
            i++;
            j++;
        }
        if (str[i] == ' ') {
            i++;
        }
    }
    str[j] = '\0';
}

// Function to print the result
void print_result(char str[]) {
    if (strlen(str) & 1) {
        if (is_palindrome(str, 0, strlen(str) - 1)) {
            printf("%s is a palindrome.\n", str);
        } else {
            printf("%s is not a palindrome.\n", str);
        }
    } else {
        if (recursive_is_palindrome(str, 0)) {
            printf("%s is a palindrome.\n", str);
        } else {
            printf("%s is not a palindrome.\n", str);
        }
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    remove_spaces(str);
    print_result(str);
    return 0;
}