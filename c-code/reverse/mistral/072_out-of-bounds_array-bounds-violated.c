#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main() {
    char str[1001];
    scanf("%s", str);
    printf("%s is %s a palindrome.\n", str, is_palindrome(str) ? "a" : "not a");
    return 0;
}
