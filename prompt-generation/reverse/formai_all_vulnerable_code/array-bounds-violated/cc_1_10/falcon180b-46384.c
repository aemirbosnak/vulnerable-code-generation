//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str);

int main() {
    char input[MAX_LENGTH];
    int length;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    length = strlen(input);
    input[length - 1] = '\0';

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int i, j;
    char *ptr;

    ptr = str;
    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        while (!isalnum(*ptr) && *ptr!= '_') {
            ptr++;
        }

        while (!isalnum(*ptr) && *ptr!= '_') {
            ptr--;
        }

        if (tolower(*ptr)!= tolower(*(ptr + 1))) {
            return 0;
        }

        i++;
        j--;
        ptr++;
    }

    return 1;
}