//Falcon-180B DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int is_palindrome(char *str);
void print_palindromes(char *str);

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (is_palindrome(input)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int length = strlen(str);

    // Check for single-character strings
    if (length == 1) {
        return 1;
    }

    // Check for two-character strings
    if (length == 2 && str[0] == str[1]) {
        return 1;
    }

    // Recursive case
    if (str[0] == str[length - 1]) {
        return is_palindrome(str + 1);
    }

    return 0;
}

// Function to print all palindromes in a given string
void print_palindromes(char *str) {
    int length = strlen(str);

    // Check for single-character strings
    if (length == 1) {
        printf("%s\n", str);
        return;
    }

    // Check for two-character strings
    if (length == 2 && str[0] == str[1]) {
        printf("%s\n", str);
        return;
    }

    // Recursive case
    for (int i = 0; i < length; i++) {
        if (str[i] == str[length - 1]) {
            str[i] = '\0';
            print_palindromes(str + i + 1);
        }
    }
}