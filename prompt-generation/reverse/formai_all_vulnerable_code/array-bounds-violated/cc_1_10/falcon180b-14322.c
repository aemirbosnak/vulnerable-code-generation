//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str) {
    int length = strlen(str);
    int i, j;

    // Remove non-alphanumeric characters and convert to lowercase
    for (i = 0; i < length; i++) {
        if (!isalnum(str[i])) {
            str[i] = '\0';
        } else {
            str[i] = tolower(str[i]);
        }
    }

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];
    int length;

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove trailing newline character
    length = strlen(input);
    if (input[length - 1] == '\n') {
        input[--length] = '\0';
    }

    // Check if input is a palindrome
    if (isPalindrome(input)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }

    return 0;
}