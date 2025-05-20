//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int i, j;
    int len = strlen(str);
    
    // Check if length is 1 or 0
    if (len <= 1) {
        return 1;
    }
    
    // Check if length is 2
    if (len == 2) {
        return 1;
    }
    
    // Check if length is 3
    if (len == 3) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2]) {
            return 1;
        }
    }
    
    // Check if length is 4
    if (len == 4) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3]) {
            return 1;
        }
    }
    
    // Check if length is 5
    if (len == 5) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4]) {
            return 1;
        }
    }
    
    // Check if length is 6
    if (len == 6) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4] && str[4] == str[len - 5]) {
            return 1;
        }
    }
    
    // Check if length is 7
    if (len == 7) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4] && str[4] == str[len - 5] && str[5] == str[len - 6]) {
            return 1;
        }
    }
    
    // Check if length is 8
    if (len == 8) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4] && str[4] == str[len - 5] && str[5] == str[len - 6] && str[6] == str[len - 7]) {
            return 1;
        }
    }
    
    // Check if length is 9
    if (len == 9) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4] && str[4] == str[len - 5] && str[5] == str[len - 6] && str[6] == str[len - 7] && str[7] == str[len - 8]) {
            return 1;
        }
    }
    
    // Check if length is 10
    if (len == 10) {
        if (str[0] == str[len - 1] && str[1] == str[len - 2] && str[2] == str[len - 3] && str[3] == str[len - 4] && str[4] == str[len - 5] && str[5] == str[len - 6] && str[6] == str[len - 7] && str[7] == str[len - 8] && str[8] == str[len - 9]) {
            return 1;
        }
    }
    
    // If not a palindrome
    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    
    // Check if string is a palindrome
    if (isPalindrome(str)) {
        printf("Yes, the string is a palindrome.\n");
    } else {
        printf("No, the string is not a palindrome.\n");
    }
    
    return 0;
}