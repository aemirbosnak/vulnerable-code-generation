//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int isPalindrome(char *str) {
    int len = strlen(str);
    reverse(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}