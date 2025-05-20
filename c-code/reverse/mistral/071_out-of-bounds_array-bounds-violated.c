#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];
    int attempts = 2, i, j, len;

    for (attempts--; attempts >= 0; attempts--) {
        printf("Enter a string (up to 1000 characters): ");
        scanf("%s", str);
        len = strlen(str);

        for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
            if (str[i] != str[j]) {
                printf("Incorrect. Try again.\n");
                break;
            }
        }

        if (i >= len / 2) {
            printf("Congratulations! The string is a palindrome.\n");
            return 0;
        }
    }

    printf("You have exceeded the number of attempts. Exiting...\n");
    return 1;
}
