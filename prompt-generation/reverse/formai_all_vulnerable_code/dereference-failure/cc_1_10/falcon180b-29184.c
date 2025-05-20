//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str, int start, int end) {
    char temp;

    // Swap characters at start and end
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next set of characters
    if (start < end - 1)
        reverseString(str, start + 1, end - 1);
}

// Function to check if a string is palindrome
int isPalindrome(char* str) {
    int len = strlen(str);

    // Base case
    if (len <= 1)
        return 1;

    // Recursive case
    if (str[0]!= str[len - 1])
        return 0;

    // Remove first and last characters and check for palindrome recursively
    return isPalindrome(str + 1);
}

int main() {
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str, 0, strlen(str) - 1);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}