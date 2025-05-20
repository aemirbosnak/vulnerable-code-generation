//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char *string);
void reverseString(char *string);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);

    if (isPalindrome(input)) {
        printf("The string is a palindrome! ");
    } else {
        printf("The string is not a palindrome! ");
    }

    return 0;
}

int isPalindrome(char *string) {
    char *start = string;
    char *end = string + strlen(string) - 1;

    while (start < end) {
        if (!isalnum(*start)) {
            start++;
        } else if (!isalnum(*end)) {
            end--;
        } else if (tolower(*start)!= tolower(*end)) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

void reverseString(char *string) {
    char *start = string;
    char *end = string + strlen(string) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}