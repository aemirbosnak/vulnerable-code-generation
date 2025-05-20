//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int is_palindrome(char* str) {
    int length = strlen(str);
    if (length < 2) {
        return 1;
    }

    char* clean_str = malloc(MAX_LENGTH * sizeof(char));
    int clean_length = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            clean_str[clean_length] = tolower(str[i]);
            clean_length++;
        }
    }
    clean_str[clean_length] = '\0';

    int is_palindrome_flag = 1;
    for (int i = 0; i < clean_length / 2; i++) {
        if (clean_str[i]!= clean_str[clean_length - i - 1]) {
            is_palindrome_flag = 0;
            break;
        }
    }

    free(clean_str);
    return is_palindrome_flag;
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input_str);

    int is_palindrome_flag = is_palindrome(input_str);

    if (is_palindrome_flag) {
        printf("%s is a palindrome.\n", input_str);
    } else {
        printf("%s is not a palindrome.\n", input_str);
    }

    return 0;
}