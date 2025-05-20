//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

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

int isPalindrome(char *str) {
    int length = strlen(str);
    if (length <= 1) {
        return 1;
    }
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }
    reverse(str, 0, length - 1);
    return strcmp(str, "") == 0;
}

int main() {
    char input[MAX_LENGTH];
    int checkCase = 1;

    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter 0 to exit, or a string to check if it's a palindrome.\n");

    while (checkCase) {
        printf("Input: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) > MAX_LENGTH) {
            printf("String too long! Max length is %d.\n", MAX_LENGTH);
            continue;
        }

        if (isPalindrome(input)) {
            printf("%s is a palindrome!\n", input);
        } else {
            printf("%s is not a palindrome.\n", input);
        }

        printf("Enter 0 to exit, or a string to check: ");
        scanf("%d", &checkCase);
    }

    return 0;
}