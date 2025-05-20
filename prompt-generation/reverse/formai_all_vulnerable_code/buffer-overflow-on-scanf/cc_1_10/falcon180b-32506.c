//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
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
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }

    return 1; // Palindrome
}

int main() {
    char str[100];
    int choice;

    // Ask user for input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Ask user for choice of operation
    printf("Choose an operation:\n");
    printf("1. Reverse the string\n");
    printf("2. Check if the string is a palindrome\n");
    scanf("%d", &choice);

    // Perform chosen operation
    switch (choice) {
        case 1:
            reverse(str);
            printf("Reversed string: %s\n", str);
            break;
        case 2:
            if (isPalindrome(str)) {
                printf("The string is a palindrome.\n");
            } else {
                printf("The string is not a palindrome.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}