#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1001];
    int attempts = 2;

    while (attempts > 0) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (isPalindrome(input)) {
            printf("The string is a palindrome.\n");
            return 0;
        } else {
            printf("The string is not a palindrome. Try again.\n");
            attempts--;
        }
    }

    printf("You have exceeded the number of attempts.\n");
    return 0;
}
