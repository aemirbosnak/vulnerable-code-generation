//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024

typedef struct {
    char* str;
    int len;
} string_t;

typedef enum {
    PALINDROME,
    NOT_PALINDROME,
    ERROR
} palindrome_status_t;

palindrome_status_t is_palindrome(string_t str) {
    if (str.len == 0) {
        return ERROR;
    }

    int i = 0;
    int j = str.len - 1;

    while (i < j) {
        if (str.str[i] != str.str[j]) {
            return NOT_PALINDROME;
        }

        i++;
        j--;
    }

    return PALINDROME;
}

int main() {
    string_t str;

    printf("Enter a string: ");
    scanf("%s", str.str);

    str.len = strlen(str.str);

    palindrome_status_t status = is_palindrome(str);

    switch (status) {
        case PALINDROME:
            printf("%s is a palindrome.\n", str.str);
            break;
        case NOT_PALINDROME:
            printf("%s is not a palindrome.\n", str.str);
            break;
        case ERROR:
            printf("Error: Invalid input.\n");
            break;
    }

    return 0;
}