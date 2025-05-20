//Falcon-180B DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to reverse a string
void reverseString(char* str, int start, int end) {
    char temp;

    // One by one move boundary of substring
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
        if (*(str+start)!= *(str+end))
            return 0; // Not a palindrome
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Recursive function to print all palindromic substrings of a string
void printPalindromes(char* str, int start, int end) {
    // Base case: Single character string is always a palindrome
    if (start >= end) {
        printf(" Palindrome: ");
        for (int i = start; i <= end; i++)
            printf("%c", str[i]);
        printf("\n");
        return;
    }

    // Recursive case: Check for all possible substrings
    for (int i = start; i <= end; i++) {
        // Exclude single character substrings
        if (i == start && i == end)
            continue;

        // Check if substring is a palindrome
        if (isPalindrome(str, start, i) && isPalindrome(str, i, end)) {
            reverseString(str, start, i-1);
            reverseString(str, i, end);
            printf(" Palindrome: ");
            for (int j = start; j <= end; j++)
                printf("%c", str[j]);
            printf("\n");
        }
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    // Call recursive function to print all palindromic substrings
    printPalindromes(str, 0, strlen(str)-1);

    return 0;
}