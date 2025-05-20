//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char* reverseString(char* str);
int isPalindrome(char* str);

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    char* reversed = reverseString(input);
    int result = isPalindrome(reversed);

    if (result == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(reversed);
    return 0;
}

char* reverseString(char* str) {
    char* reversed = malloc(strlen(str) + 1);
    int i = strlen(str) - 1, j = 0;

    while (i >= 0) {
        reversed[j++] = tolower(str[i]);
        i--;
    }

    reversed[j] = '\0';
    return reversed;
}

int isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}