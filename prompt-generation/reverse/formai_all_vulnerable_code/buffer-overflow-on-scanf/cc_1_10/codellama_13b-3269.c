//Code Llama-13B DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a palindrome using pointers
int is_palindrome_ptr(char* str) {
    int len = strlen(str);
    char* end = str + len - 1;
    for (char* p = str; p < end; p++, end--) {
        if (*p != *end) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a palindrome using recursion
int is_palindrome_rec(char* str, int len) {
    if (len <= 1) {
        return 1;
    }
    if (str[0] != str[len - 1]) {
        return 0;
    }
    return is_palindrome_rec(str + 1, len - 2);
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}