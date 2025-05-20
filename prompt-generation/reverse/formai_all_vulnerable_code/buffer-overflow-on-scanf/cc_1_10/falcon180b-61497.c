//Falcon-180B DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to print a string in reverse order
void printReverse(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Recursive function to check if a string is a palindrome
int isPalindrome(char* str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    else if (str[start]!= str[end]) {
        return 0;
    }
    else {
        return isPalindrome(str, start + 1, end - 1);
    }
}

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    char* reversed = reverseString(input);
    if (isPalindrome(input, 0, strlen(input) - 1)) {
        printf("The string is a palindrome.\n");
        printf("Reversed string: %s\n", reversed);
    }
    else {
        printf("The string is not a palindrome.\n");
    }
    free(reversed);
    return 0;
}