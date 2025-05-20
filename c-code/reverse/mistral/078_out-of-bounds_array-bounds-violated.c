#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10000

int is_palindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];
    scanf("%s", str);
    int len = strlen(str);
    if (is_palindrome(str, 0, len - 1))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}
