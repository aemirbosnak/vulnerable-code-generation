//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void reverse(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    int length = strlen(str);
    if (length <= 1)
        return 1;

    reverse(str, 0, length - 1);

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", input);

    if (is_palindrome(input))
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    return 0;
}

/* Ada Lovelace, the world's first computer programmer,
   would be proud of this elegant and efficient code. */