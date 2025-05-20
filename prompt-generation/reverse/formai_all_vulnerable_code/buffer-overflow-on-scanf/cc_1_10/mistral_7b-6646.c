//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 101

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        start++;
        end--;
    }
}

int palindromeChecker(char *str) {
    int length = strlen(str);
    if (length < 2) return 1;

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    reverse(str, 0, length - 1);

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[SIZE];

    printf("Welcome, Space Traveler, to the Palindrome Time Machine!\n");
    printf("Enter a word or phrase to check for palindromicity: ");
    scanf("%s", input);

    if (palindromeChecker(input)) {
        printf("Space Traveler, your input is a palindrome!\n");
    } else {
        printf("Space Traveler, your input is not a palindrome.\n");
    }

    return 0;
}