//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void reverse_string(char *str, int length) {
    int i = 0;
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf(" %s %s\n", "->", str);
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int is_palindrome(const char *str) {
    int length = strlen(str);
    if (length <= 1) {
        return 1;
    }

    if (tolower(str[0]) != tolower(str[length - 1])) {
        return 0;
    }

    reverse_string(str, length);

    int i = 0;
    for (i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];

    printf("\nWelcome to The Enchanted Mirror of Palindromes! Enter a word and let's see if it's magical.\n");

    scanf("%s", input);

    if (is_palindrome(input)) {
        printf("\nCongratulations! You have entered a palindrome.\n");
    } else {
        printf("\nI'm sorry, that's not a palindrome. But don't be disheartened! Let's try another one.\n");
    }

    return 0;
}