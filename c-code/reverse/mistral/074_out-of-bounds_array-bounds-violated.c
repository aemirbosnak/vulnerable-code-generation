#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char input[BUFFER_SIZE];
    int i, len;

    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);

    len = strlen(input);

    if (len > BUFFER_SIZE - 1) {
        printf("Error: String too long.\n");
        return 1;
    }

    for (i = 0; i < len / 2; ++i) {
        if (input[i] != input[len - i - 1]) {
            printf("Error: Not a palindrome.\n");
            return 1;
        }
    }

    if (len % 2 == 1) {
        printf("The middle character is %c.\n", input[(len - 1) / 2]);
    } else {
        printf("The middle characters are %c and %c.\n", input[(len - 1) / 2], input[(len - 2) / 2]);
    }

    printf("The string is a palindrome.\n");
    return 0;
}
