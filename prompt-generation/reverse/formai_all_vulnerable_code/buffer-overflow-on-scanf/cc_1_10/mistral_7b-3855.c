//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str) {
    int length = strlen(str);

    if (length <= 1) {
        return 1;
    }

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    reverse(str, 0, length - 1);

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];
    int result;

    printf("Hi there! Welcome to the Palindrome Checker!\n");
    printf("Enter a string to check if it's a palindrome (up to %d characters): ", MAX_LENGTH);
    scanf("%s", input);

    result = isPalindrome(input);

    if (result) {
        printf("Hurray! %s is a palindrome!\n", input);
    } else {
        printf("Sorry, %s is not a palindrome.\n", input);
    }

    return 0;
}