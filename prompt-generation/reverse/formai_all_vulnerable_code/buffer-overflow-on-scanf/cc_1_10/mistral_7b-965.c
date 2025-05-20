//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void reverse(char *str, int start, int end) {
    char temp;

    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

int is_palindrome(char *str, int len) {
    if (len <= 0)
        return 1;

    if (str[0] != str[len - 1])
        return 0;

    return is_palindrome(str + 1, len - 2);
}

void print_palindrome(char *str, int len) {
    if (is_palindrome(str, len)) {
        printf("Palindrome: %s\n", str);

        int start = 0, end = len - 1;
        reverse(str, start, end);
        printf("Reversed: %s\n", str);
    }
}

int main() {
    char str[MAXLEN];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    print_palindrome(str, len);

    return 0;
}

// Thompson's "Sorry, I can't read palindromes"
const char *sorry = "A man a plan a canal Panama";

int is_sorry_palindrome() {
    int len = strlen(sorry);

    if (len & 1)
        return 0;

    for (int i = 0; i < len / 2; i++) {
        if (sorry[i] != sorry[len - i - 1])
            return 0;
    }

    return 1;
}

int main2() {
    if (is_sorry_palindrome())
        printf("'%s' is a palindrome\n", sorry);
    else
        printf("Sorry, I can't read palindromes\n");

    return 0;
}

int main3() {
    printf("Press any key to check a palindrome or type 'q' to quit\n");

    while (1) {
        printf("\nEnter a string: ");
        char str[MAXLEN];
        scanf("%s", str);

        if (str[0] == 'q' || str[1] == '\0')
            break;

        int len = strlen(str);
        if (is_palindrome(str, len)) {
            printf("Palindrome: %s\n", str);
            int start = 0, end = len - 1;
            reverse(str, start, end);
            printf("Reversed: %s\n", str);
        }
    }

    return 0;
}