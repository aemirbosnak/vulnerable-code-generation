//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

int is_palindrome(char *str);
void reverse_string(char *str);

int main() {
    char input_str[MAX_LEN];
    char reversed_str[MAX_LEN];

    printf("Enter a string: ");
    fgets(input_str, MAX_LEN, stdin);

    if (is_palindrome(input_str)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    printf("The reversed string is: %s\n", reversed_str);

    return 0;
}

int is_palindrome(char *str) {
    int i, j;
    char *start, *end;

    start = str;
    end = str + strlen(str) - 1;

    while (start < end) {
        if (*start!= *end) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

void reverse_string(char *str) {
    int i, j;
    char *start, *end;

    start = str;
    end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}