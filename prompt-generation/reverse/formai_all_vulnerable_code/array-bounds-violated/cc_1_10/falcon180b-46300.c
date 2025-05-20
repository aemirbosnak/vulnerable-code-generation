//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // maximum length of input string

int isPalindrome(char *str); // function to check if a string is a palindrome

int main() {
    char input[MAX_LENGTH]; // input string
    int length; // length of input string

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin); // read input string from user

    length = strlen(input); // get length of input string

    // remove leading and trailing whitespace from input string
    input[--length] = '\0';
    while (isspace(input[0])) {
        memmove(input, input + 1, length);
        length--;
    }

    // check if input string is a palindrome
    if (isPalindrome(input)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int length = strlen(str); // get length of input string
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0; // not a palindrome
        }
        i++;
        j--;
    }

    return 1; // is a palindrome
}