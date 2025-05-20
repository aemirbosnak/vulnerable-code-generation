//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str) {
    char cleanStr[MAX_LENGTH];
    int i, j, len;
    
    len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        cleanStr[i] = tolower(str[i]);
        cleanStr[j] = tolower(str[j]);
    }
    cleanStr[j] = '\0';
    
    for (i = 0; i < j; i++) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char inputStr[MAX_LENGTH];
    int isPal = 0;
    
    printf("Enter a string to check if it's a palindrome: ");
    fgets(inputStr, MAX_LENGTH, stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';
    
    if (isPalindrome(inputStr)) {
        printf("%s is a palindrome.\n", inputStr);
        isPal = 1;
    } else {
        printf("%s is not a palindrome.\n", inputStr);
    }
    
    if (isPal == 0) {
        printf("Enter another string to check: ");
        fgets(inputStr, MAX_LENGTH, stdin);
        inputStr[strcspn(inputStr, "\n")] = '\0';
        
        if (isPalindrome(inputStr)) {
            printf("%s is a palindrome.\n", inputStr);
        } else {
            printf("%s is not a palindrome.\n", inputStr);
        }
    }
    
    return 0;
}