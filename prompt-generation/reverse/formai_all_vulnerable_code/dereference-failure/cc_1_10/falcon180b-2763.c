//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int isPalindrome(char*);
int isPalindromeIgnoreCase(char*);
int isPalindromeIgnoreSpaces(char*);

int main() {
    char input[MAX_SIZE];
    int choice;
    printf("Palindrome Checker\n");
    printf("Enter a string: ");
    scanf("%s", input);
    printf("Choose an option:\n");
    printf("1. Check for palindrome\n");
    printf("2. Check for palindrome ignoring case\n");
    printf("3. Check for palindrome ignoring spaces\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            if(isPalindrome(input)) {
                printf("The string is a palindrome.\n");
            } else {
                printf("The string is not a palindrome.\n");
            }
            break;
        case 2:
            if(isPalindromeIgnoreCase(input)) {
                printf("The string is a palindrome ignoring case.\n");
            } else {
                printf("The string is not a palindrome ignoring case.\n");
            }
            break;
        case 3:
            if(isPalindromeIgnoreSpaces(input)) {
                printf("The string is a palindrome ignoring spaces.\n");
            } else {
                printf("The string is not a palindrome ignoring spaces.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(str[i]!= str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int isPalindromeIgnoreCase(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(tolower(str[i])!= tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}

int isPalindromeIgnoreSpaces(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc(len+1);
    int j = 0;
    for(int i=0; i<len; i++) {
        if(!isspace(str[i])) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    int result = isPalindrome(newStr);
    free(newStr);
    return result;
}