#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int is_palindrome(char *str) {
    int len = strlen(str);
    char buf[50];
    strcpy(buf, str);

    for (int i = 0; i < len / 2; i++) {
        if (buf[i] != buf[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[60];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
