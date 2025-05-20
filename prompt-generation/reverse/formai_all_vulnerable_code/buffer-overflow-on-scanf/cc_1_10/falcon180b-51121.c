//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    // Swap characters
    while (i < j) {
        temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;

        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    // Compare characters from both ends
    while (i < j) {
        if (*(str + i)!= *(str + j)) {
            return 0; // Not a palindrome
        }

        i++;
        j--;
    }

    return 1; // Palindrome
}

int main() {
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverse(str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}