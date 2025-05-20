#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int is_palindrome(char str[]) {
    int left = 0, right = MAX_LENGTH - 1, check = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            check = 0;
            break;
        }
        left++;
        right--;
    }

    return check;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
