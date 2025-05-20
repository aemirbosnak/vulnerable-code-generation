//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str);
void reverseString(char *str);

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int i, j;
    char *p;

    // Remove non-alphanumeric characters and convert to lowercase
    p = str;
    while (*p) {
        if (!isalnum(*p)) {
            *p = '\0';
        }
        p++;
    }

    // Check if the reversed string is equal to the original string
    reverseString(str);
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}