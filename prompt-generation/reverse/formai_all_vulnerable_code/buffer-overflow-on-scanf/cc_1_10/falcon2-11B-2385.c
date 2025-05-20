//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    int len = 0;
    while (str[len]!= '\0') {
        len++;
    }
    len /= 2;
    int start = 0;
    int end = len - 1;
    while (start < end) {
        if (str[start]!= str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to check if a string is a rotational or reflection symmetry
bool isSymmetric(char* str) {
    int len = 0;
    while (str[len]!= '\0') {
        len++;
    }
    len /= 2;
    int start = 0;
    int end = len - 1;
    while (start < end) {
        if (str[start]!= str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Is the string a palindrome? %s\n", isPalindrome(str)? "Yes" : "No");
    printf("Is the string a rotational or reflection symmetry? %s\n", isSymmetric(str)? "Yes" : "No");
    return 0;
}