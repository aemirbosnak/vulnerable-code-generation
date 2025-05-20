//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all duplicates from a string
void removeDuplicates(char* str) {
    int i, j;
    char* dup = NULL;

    // Find the first duplicate character
    for (i = 0; i < strlen(str) - 1; i++) {
        dup = strchr(str + i + 1, str[i]);
        if (dup!= NULL) {
            break;
        }
    }

    // Remove all occurrences of the duplicate character
    if (dup!= NULL) {
        for (j = i; j < strlen(str); j++) {
            if (str[j] == *(dup + 1)) {
                str[j] = '\0';
            }
        }
    }
}

// Function to reverse a string
void reverseString(char* str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    // Remove all duplicates
    removeDuplicates(input);

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