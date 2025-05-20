//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char str[101];
    int len;
} Palindrome;

void mirror(Palindrome *palindrome, int start, int end) {
    while (start < end) {
        palindrome->str[start] = toupper(palindrome->str[end]);
        start++;
        end--;
    }
}

int is_palindrome(Palindrome palindrome) {
    int len = palindrome.len;
    if (len <= 1) return 1;
    for (int i = 0; i < len / 2; i++) {
        if (palindrome.str[i] != palindrome.str[len - i - 1]) {
            return 0;
        }
    }
    mirror(&palindrome, 0, len - 1);
    for (int i = 0; i < len / 2; i++) {
        if (palindrome.str[i] != palindrome.str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[101];
    Palindrome palindrome;

    printf("Enter a surrealist palindrome: ");
    scanf("%s", input);

    strcpy(palindrome.str, input);
    palindrome.len = strlen(input);

    if (is_palindrome(palindrome)) {
        printf("Surrealist palindrome detected!\n");
    } else {
        printf("Sorry, that is not a surrealist palindrome.\n");
    }

    return 0;
}