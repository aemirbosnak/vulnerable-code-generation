//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

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

int is_palindrome(char *str) {
    int len = strlen(str);

    if (len <= 1) {
        return 1;
    }

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    reverse(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];
    int result;

    printf("I'm not only a Palindrome Checker, I'm a mind-bending, reality-twisting, time-traveling, quantum-leaping, palindromic marvel!\n");
    printf("Enter a string: ");
    scanf("%s", str);

    result = is_palindrome(str);

    if (result == 1) {
        printf("Wow! You've entered a palindrome!\n");
    } else {
        printf("Are you sure about that? Let me check again...\n");
        reverse(str, 0, strlen(str) - 1);
        result = is_palindrome(str);

        if (result == 1) {
            printf("My apologies for doubting you, but you were indeed correct!\n");
        } else {
            printf("I'm sorry, but your string is not a palindrome.\n");
        }
    }

    return 0;
}