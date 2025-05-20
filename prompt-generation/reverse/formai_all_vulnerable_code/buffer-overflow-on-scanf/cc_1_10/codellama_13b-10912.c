//Code Llama-13B DATASET v1.0 Category: System boot optimizer ; Style: Sherlock Holmes
/*
 * A unique C System boot optimizer example program in a Sherlock Holmes style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

// Main function
int main(void) {
    // Get input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");

        // Reverse the string
        reverse(str);

        // Check if the reversed string is a palindrome
        if (isPalindrome(str)) {
            printf("The reversed string is a palindrome.\n");
        } else {
            printf("The reversed string is not a palindrome.\n");
        }
    }

    return 0;
}