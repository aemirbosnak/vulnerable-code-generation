//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char str[MAX_STRING_LENGTH];
    int len;
} String;

String shift_left(String str) {
    int i;
    for (i = 0; i < str.len - 1; i++) {
        str.str[i] = str.str[i + 1];
    }
    str.str[i] = '\0';
    str.len--;
    return str;
}

String shift_right(String str) {
    int i;
    for (i = str.len - 1; i >= 0; i--) {
        str.str[str.len - 1] = str.str[i];
    }
    str.str[str.len] = '\0';
    str.len++;
    return str;
}

int is_palindrome(String str) {
    int i;
    for (i = 0; i < str.len / 2; i++) {
        if (str.str[i] != str.str[str.len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    String input;
    char c;
    int i;

    printf("Enter a string: ");
    fgets(input.str, MAX_STRING_LENGTH, stdin);
    input.len = strlen(input.str);
    input.str[input.len - 1] = '\0'; // remove newline character

    if (input.len & 1) { // odd length palindrome is impossible
        printf("Error: Palindromes must have even length.\n");
        return 1;
    }

    for (i = 0; i < input.len / 2; i++) {
        if (input.str[i] != input.str[input.len - i - 1]) {
            printf("Error: '%c' at position %d does not match '%c' at position %d.\n",
                input.str[i], i, input.str[input.len - i - 1], input.len - i - 1);
            return 1;
        }
    }

    printf("'%s' is a palindrome.\n", input.str);

    printf("Shift left: ");
    for (i = 0; i < 5; i++) {
        input = shift_left(input);
        printf("%s ", input.str);
    }
    printf("\n");

    printf("Shift right: ");
    for (i = 0; i < 5; i++) {
        input = shift_right(input);
        printf("%s ", input.str);
    }
    printf("\n");

    return 0;
}