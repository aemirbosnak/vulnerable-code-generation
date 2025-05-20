#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

void checkPalindromes() {
    char str[100];
    while (1) {
        printf("Enter a string (or 'exit' to quit): ");
        scanf("%s", str);
        if (strcmp(str, "exit") == 0) {
            break;
        }
        if (isPalindrome(str)) {
            printf("%s is a palindrome.\n", str);
        } else {
            printf("%s is not a palindrome.\n", str);
        }
    }
}

int main() {
    checkPalindromes();
    return 0;
}
