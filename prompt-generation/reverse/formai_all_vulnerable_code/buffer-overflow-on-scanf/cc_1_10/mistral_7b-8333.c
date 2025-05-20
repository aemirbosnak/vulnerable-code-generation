//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

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
    if (len < 2)
        return 1;

    reverse(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }

    return 1;
}

void print_letter_count(char *str) {
    int count[26] = {0};

    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            count[str[i] - 'a']++;
        }
    }

    printf("\nLetter count:\n");
    for (int i = 0; i < 26; i++) {
        if (count[i])
            printf("%c : %d\n", i + 'a', count[i]);
    }
}

void replace_all(char *str, char find, char replace) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == find)
            str[i] = replace;
    }
}

void main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("\nIs palindrome: %d\n", is_palindrome(str));

    print_letter_count(str);

    replace_all(str, 'a', 'e');
    printf("\nReplaced all 'a' with 'e': %s\n", str);

    reverse(str, 0, strlen(str) - 1);
    printf("\nReversed string: %s\n", str);
}