//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

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

    while (i < j) {
        if (*(str + i)!= *(str + j)) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() {
    char input[100];
    char reversed[100];
    int isPal;

    // Get input from user
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);

    // Check if the reversed string is a palindrome
    isPal = isPalindrome(input);

    // Print the result
    if (isPal == 1) {
        printf("The input string is a palindrome.\n");
    }
    else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}