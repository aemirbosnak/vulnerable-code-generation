//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(char* s, int start, int end) {
    // Base case: if start and end meet in the middle, it's a palindrome
    if (start >= end) {
        return true;
    }
    
    // Ignore non-alphabetic characters and move the pointers
    while (!isalpha(s[start])) {
        start++;
    }
    while (!isalpha(s[end])) {
        end--;
    }
    
    // Convert to lower case to ignore case sensitivity
    char c1 = tolower(s[start]);
    char c2 = tolower(s[end]);
    
    // If the characters at start and end do not match, it's not a palindrome
    if (c1 != c2) {
        return false;
    }
    
    // Recursive call to check if the remaining substring is a palindrome
    return is_palindrome(s, start+1, end-1);
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    fgets(s, 1000, stdin);
    
    int len = strlen(s);
    if (s[len-1] == '\n') {  // Remove the newline character if present
        s[len-1] = '\0';
    }
    
    if (is_palindrome(s, 0, len-1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}