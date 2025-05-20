//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i = 0;
    int j = length - 1;
    while (i < j) {
        reversed[i++] = tolower(str[j--]);
    }
    reversed[i] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i])!= tolower(str[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    int length = strlen(input);
    while (isspace(input[0])) {
        strcpy(input, &input[1]);
        length--;
    }
    while (isspace(input[length - 1])) {
        input[--length] = '\0';
    }

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Reverse the string
    reverseString(input);

    return 0;
}