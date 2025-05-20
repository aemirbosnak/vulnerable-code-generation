//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void swap(char* x, char* y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int checkPalindrome(char input[]) {
    int length = strlen(input);
    if (length < 2) {
        return 1;
    }

    // Convert to lowercase
    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }

    return isPalindrome(input, 0, length - 1);
}

void reverseString(char str[], int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

void printReversed(char str[]) {
    int length = strlen(str);
    if (length < 1) {
        return;
    }

    printf("%c", str[length - 1]);
    reverseString(str, 0, length - 2);
}

void printPalindrome(char str[]) {
    if (!checkPalindrome(str)) {
        printf("Sorry, that's not a palindrome!\n");
        return;
    }

    printf("Wow, that's a palindrome!\n");
    printReversed(str);
    printf("\n");
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    printPalindrome(str);

    return 0;
}