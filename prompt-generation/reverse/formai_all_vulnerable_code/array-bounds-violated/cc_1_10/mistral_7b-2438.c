//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

void reverseString(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void printReverse(char *str) {
    int len = strlen(str);
    reverseString(str, 0, len - 1);
    printf("%s\n", str);
}

int isPalindrome(char *str, int len) {
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    size_t length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    if (isPalindrome(input, strlen(input))) {
        printf("The given string is a palindrome.\n");
        printReverse(input);
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}