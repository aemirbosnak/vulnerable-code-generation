//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int is_palindrome(char *str, int len) {
    int left = 0, right = len - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

void reverse_string(char *str, int len) {
    int i = 0;
    char temp;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
}

int main(void) {
    char input[MAX_LEN];
    int len, result;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    len = strlen(input);
    input[len - 1] = '\0'; // Remove newline character

    if (len > MAX_LEN) {
        printf("String too long.\n");
        return 1;
    }

    reverse_string(input, len);

    result = is_palindrome(input, len);

    if (result) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}