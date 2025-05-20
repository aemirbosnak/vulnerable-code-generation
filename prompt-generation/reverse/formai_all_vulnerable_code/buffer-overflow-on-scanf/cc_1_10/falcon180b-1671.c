//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all non-alphabetic characters from a string
void removeNonAlphabetic(char* str) {
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char input[100];

    // Get user input
    printf("Enter a string: ");
    scanf("%s", input);

    // Remove non-alphabetic characters
    removeNonAlphabetic(input);

    // Reverse the string
    reverseString(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}