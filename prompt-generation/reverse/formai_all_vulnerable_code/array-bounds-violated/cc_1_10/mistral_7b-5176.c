//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define ART_SIZE 40

void print_art(void) {
    int i;
    for (i = 0; i < ART_SIZE; i++) {
        putchar('*');
        if (i % 10 == 9) putchar('\n');
    }
}

void reverse_string(char *str, int len) {
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

bool is_palindrome(char *str, int len) {
    int i;

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    char input[1024];
    char *str;
    int len;

    print_art();
    puts("Welcome to the Palindrome Checker!");
    print_art();

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    len = strlen(input) - 1;

    if (input[len] != '\n') len++;

    str = malloc(len + 1);
    strncpy(str, input, len + 1);

    reverse_string(str, len);

    if (is_palindrome(str, len)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    free(str);

    print_art();
    return 0;
}