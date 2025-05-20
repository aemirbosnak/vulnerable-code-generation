//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// Function to remove all non-alphabetic characters from a string
void remove_non_alphabetic(char *str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    // Get a string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    // Convert the string to lowercase
    to_lowercase(str);
    printf("Lowercase: %s\n", str);

    // Remove all non-alphabetic characters from the string
    remove_non_alphabetic(str);
    printf("Non-alphabetic characters removed: %s\n", str);

    return 0;
}