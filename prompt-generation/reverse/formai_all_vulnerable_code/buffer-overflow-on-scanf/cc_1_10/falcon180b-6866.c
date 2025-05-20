//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    int i, j;
    char vowels[] = "AEIOUaeiou";
    int len = strlen(str);

    // Remove all vowels from the string
    for (i = 0, j = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* reverse_str = malloc(MAX_SIZE * sizeof(char));
    int i, j;

    // Reverse the string
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reverse_str[j] = str[i];
    }
    reverse_str[j] = '\0';

    // Copy the reversed string to the original string
    strcpy(str, reverse_str);
    free(reverse_str);
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    int i;

    // Check if the string is a palindrome
    for (i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all vowels from the string
    remove_vowels(str);

    // Reverse the string
    reverse_string(str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}