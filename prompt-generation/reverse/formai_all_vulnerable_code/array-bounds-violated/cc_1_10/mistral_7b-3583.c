//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

bool is_palindrome_recursive(const char *str, int start, int end);
bool is_palindrome_dp(const char *str);

int main(void) {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove newline character

    if (is_palindrome_dp(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}

bool is_palindrome_recursive(const char *str, int start, int end) {
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return is_palindrome_recursive(str, start + 1, end - 1);
}

bool is_palindrome_dp(const char *str) {
    bool table[MAX_SIZE][MAX_SIZE];
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            if (i == j)
                table[i][j] = true;
            else if (i > j)
                table[i][j] = false;
            else
                table[i][j] = str[i] == str[j] && table[i + 1][j - 1];
        }
    }

    return table[0][len - 1];
}