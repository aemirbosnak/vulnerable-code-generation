//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

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
    int length = strlen(str);
    if (length <= 1) {
        return 1;
    }
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }
    reverseString(str, 0, length - 1);
    if (strlen(str) > length) {
        return 0;
    }
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("Wow! That's a palindrome!\n");
    } else {
        printf("Oh no! That's not a palindrome.\n");
        reverseString(input, 0, strlen(input) - 1);
        printf("But wait! Let me reverse it for you:\n");
        printf("%s\n", input);
        if (isPalindrome(input)) {
            printf("And yes, it's a palindrome after all!\n");
        }
    }

    return 0;
}