#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str, int len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right]))
            return 0;
        left++;
        right--;
    }

    return 1;
}

int main() {
    char input[1001];
    int attempts = 2;

    printf("Enter a string (max length 1000 characters):\n");
    for (int i = 0; i < attempts; ++i) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (is_palindrome(input, strlen(input))) {
            printf("The string is a palindrome.\n");
            return 0;
        }
        if (i < attempts - 1)
            printf("Incorrect input. Try again.\n");
        else
            printf("You have exceeded the number of attempts. Exiting.\n");
        printf("Enter a string (max length 1000 characters):\n");
    }

    return 0;
}
