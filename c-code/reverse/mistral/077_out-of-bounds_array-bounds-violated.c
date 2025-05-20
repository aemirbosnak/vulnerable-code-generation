#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main() {
    char input[100];

    while (1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);

        if (is_palindrome(input)) {
            printf("The string is a palindrome.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }

        printf("Enter another string (type 'q' to quit): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'q' || choice == 'Q') {
            break;
        }
    }

    return 0;
}
