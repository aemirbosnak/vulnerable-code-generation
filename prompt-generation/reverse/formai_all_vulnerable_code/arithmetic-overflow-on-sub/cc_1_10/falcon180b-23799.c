//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_WORD_LENGTH 200

int main() {
    setlocale(LC_ALL, "");
    wchar_t input_word[MAX_WORD_LENGTH];
    wchar_t reversed_word[MAX_WORD_LENGTH];
    int word_length;
    bool is_palindrome = true;
    char word[MAX_WORD_LENGTH];
    char reversed_word_c[MAX_WORD_LENGTH];
    int i, j;

    printf("Enter a word: ");
    fgetws(input_word, MAX_WORD_LENGTH, stdin);
    word_length = wcslen(input_word);

    for (i = 0; i < word_length; i++) {
        input_word[i] = towlower(input_word[i]);
    }

    for (i = 0, j = word_length - 1; i < j; i++, j--) {
        reversed_word[i] = input_word[j];
        reversed_word[j] = input_word[i];
    }

    wcscpy(reversed_word + word_length, L"");

    for (i = 0; i < word_length; i++) {
        reversed_word_c[i] = towlower(reversed_word[i]);
    }

    if (wcscmp(input_word, reversed_word)!= 0) {
        is_palindrome = false;
    }

    if (is_palindrome) {
        printf("%s is a palindrome.\n", input_word);
    } else {
        printf("%s is not a palindrome.\n", input_word);
    }

    return 0;
}