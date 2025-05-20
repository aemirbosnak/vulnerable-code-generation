//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char* str) {
    int i, j;
    char temp;

    // Swap characters
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;
    char temp;

    // Check if the string is empty
    if (strlen(str) == 0) {
        return 1;
    }

    // Remove spaces and punctuation marks
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            str[i] = '\0';
        }
    }

    // Reverse the string
    reverseString(str);

    // Compare the original and reversed strings
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}