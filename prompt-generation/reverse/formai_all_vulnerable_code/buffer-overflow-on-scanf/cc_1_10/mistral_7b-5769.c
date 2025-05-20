//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 101

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

int is_palindrome(char *str, int length) {
    if (length <= 1)
        return 1;

    if (tolower(str[0]) != tolower(str[length - 1]))
        return 0;

    return is_palindrome(str + 1, length - 2);
}

void print_palindrome(char *str) {
    int len = strlen(str);

    printf("\n%s is ", str);

    if (is_palindrome(str, len))
        printf("a palindrome.\n");
    else
        printf("not a palindrome.\n");

    printf("Here is it's reversed version:\n");

    reverse(str, 0, len - 1);
    printf("%s\n", str);
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", input);

    print_palindrome(input);

    return 0;
}