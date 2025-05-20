//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A macro to define the maximum length of a string
#define MAX_STRING_LENGTH 100

// A function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// A function to convert a string to lowercase
void toLowerCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// A function to convert a string to uppercase
void toUpperCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

// A function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// A function to print a string in a box
void printInBox(char *str) {
    int len = strlen(str);
    printf("+");
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
    printf("| %s |\n", str);
    printf("+");
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    // Get a string from the user
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Convert the string to lowercase
    toLowerCase(str);

    // Convert the string to uppercase
    toUpperCase(str);

    // Check if the string is a palindrome
    int is_palindrome = isPalindrome(str);

    // Print the string in a box
    printInBox(str);

    // Print the results
    printf("Reversed string: %s\n", str);
    printf("Lowercase string: %s\n", str);
    printf("Uppercase string: %s\n", str);
    printf("Is palindrome: %s\n", is_palindrome ? "Yes" : "No");

    return 0;
}