//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str, int start, int end) {
    char temp;
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
void findPalindromes(char* str, int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (i == end) {
            // Base case: single character is a palindrome
            printf("%c ", str[i]);
        } else if (isPalindrome(str, i, end)) {
            // Recursive case: found a palindrome
            printf("%c", str[i]);
            findPalindromes(str, i+1, end);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    findPalindromes(str, 0, strlen(str)-1);
    printf("\n");
    return 0;
}