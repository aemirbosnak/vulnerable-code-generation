//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024

void reverse_str(char *str, int start, int end) {
    char temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

int is_palindrome(char *str, int len) {
    int i = 0;
    reverse_str(str, 0, len - 1);
    for (; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char str[MAX_STR_LEN];
    int len, i, j;

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    len = strlen(str);

    if (len > MAX_STR_LEN - 1) {
        printf("String too long!\n");
        return 1;
    }

    str[len] = '\0';

    // remove newline character from input
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("The given string is %s.\n", str);

    if (is_palindrome(str, len)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    printf("Enter a position to reverse a substring: ");
    scanf("%d", &i);

    printf("Enter the length of the substring: ");
    scanf("%d", &j);

    reverse_str(str, i, i + j);

    printf("The reversed substring is %s.\n", str);

    return 0;
}