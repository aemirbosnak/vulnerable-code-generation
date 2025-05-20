//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void reverse_string(char *str, int start, int end) {
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
    if (len <= 1)
        return 1;

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    reverse_string(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_palindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}