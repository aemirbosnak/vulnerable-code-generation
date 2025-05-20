//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str)
{
    int i, j, length;
    char cleanedStr[MAX_LENGTH];
    
    // Remove all non-alphanumeric characters and convert to lowercase
    length = strlen(str);
    for (i = 0, j = 0; i < length; i++) {
        if (isalnum(str[i])) {
            cleanedStr[j++] = tolower(str[i]);
        }
    }
    cleanedStr[j] = '\0';
    
    // Compare cleaned string with its reverse
    for (i = 0, j = strlen(cleanedStr) - 1; i < j; i++, j--) {
        if (cleanedStr[i]!= cleanedStr[j]) {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    char input[MAX_LENGTH];
    
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    if (isPalindrome(input)) {
        printf("The string \"%s\" is a palindrome.\n", input);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", input);
    }
    
    return 0;
}