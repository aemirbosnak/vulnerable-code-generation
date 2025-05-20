//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str, int start, int end) {
    char temp;

    // Swap characters
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (*(str+start)!= *(str+end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Recursive function to find all palindromes in a string
void findPalindromes(char* str, int start, int end, int* palindromeCount) {
    // Base case
    if (start >= end) {
        return;
    }

    // Check if the substring is a palindrome
    if (isPalindrome(str, start, end)) {
        (*palindromeCount)++;
    }

    // Recursive case
    findPalindromes(str, start, end-1, palindromeCount);
    findPalindromes(str, start+1, end, palindromeCount);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int palindromeCount = 0;
    findPalindromes(str, 0, strlen(str)-1, &palindromeCount);

    printf("Number of palindromes found: %d\n", palindromeCount);

    return 0;
}