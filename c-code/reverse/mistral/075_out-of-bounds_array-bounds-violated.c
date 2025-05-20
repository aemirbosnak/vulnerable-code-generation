#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str);

    while (start < end) {
        if (tolower(str[start]) != tolower(str[--end])) {
            return 0;
        }
        start++;
    }

    return 1;
}

int main() {
    char buffer[1024];
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (is_palindrome(buffer)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}
