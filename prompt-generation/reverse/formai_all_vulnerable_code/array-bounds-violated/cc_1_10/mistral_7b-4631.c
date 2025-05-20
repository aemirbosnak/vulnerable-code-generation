//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

bool is_palindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}

void reverse_string(char str[], int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

bool check_palindrome(char str[]) {
    int length = strlen(str);
    if (length <= 1) {
        return true;
    }

    // Check characters at the beginning and the end
    if (str[0] != str[length - 1]) {
        return false;
    }

    // Reverse the substring in the middle and compare it with the original substring
    reverse_string(str, 0, (length / 2) - 1);
    if (!is_palindrome(str, length / 2, length - 1)) {
        return false;
    }

    return true;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0'; // Remove newline character

    if (check_palindrome(str)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    return 0;
}