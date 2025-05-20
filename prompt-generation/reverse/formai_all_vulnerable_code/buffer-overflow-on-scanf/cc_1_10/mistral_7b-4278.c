//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

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

int isPalindrome(char *str) {
    int len = strlen(str);
    if (len <= 1)
        return 1;

    reverseString(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Hello there, awesome programmer!\n");
    printf("Get ready to reverse a string and check if it's a palindrome!\n");
    printf("Input a string (max length %d): ", MAX_LENGTH);
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("\nWow, you entered a palindrome! %s is the same forwards and backwards.\n", input);
    } else {
        printf("\nSorry, that's not a palindrome. Keep trying and you'll get there!\n");
    }

    reverseString(input, 0, strlen(input) - 1);
    printf("Here's your reversed string: %s\n", input);

    return 0;
}