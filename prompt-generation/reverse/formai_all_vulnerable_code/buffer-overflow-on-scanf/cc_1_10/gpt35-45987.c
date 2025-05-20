//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1);
}

int palindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (str[start] != str[end]) {
        return 0;
    }

    return palindrome(str, start + 1, end - 1);
}

void replace(char str[], char from, char to, int i) {
    if (str[i] == '\0') {
        return;
    }

    if (str[i] == from) {
        str[i] = to;
    }

    replace(str, from, to, i + 1);
}

int main() {
    char str[50];
    printf("Enter a string (max 50 characters): ");
    scanf("%s", str);

    // Reverse string
    printf("Original string: %s\n", str);
    reverse(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n\n", str);

    // Check for palindrome
    int pal = palindrome(str, 0, strlen(str) - 1);
    if (pal == 1) {
        printf("The string is a palindrome.\n\n");
    } else {
        printf("The string is not a palindrome.\n\n");
    }

    // Replace characters
    char from, to;
    printf("Enter a character to replace: ");
    scanf(" %c", &from);
    printf("Enter replacing character: ");
    scanf(" %c", &to);
    replace(str, from, to, 0);
    printf("Modified string: %s\n", str);

    return 0;
}