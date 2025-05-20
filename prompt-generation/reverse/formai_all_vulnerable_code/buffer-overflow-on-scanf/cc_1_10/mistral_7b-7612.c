//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

// Palindrome checker in a medieval style

typedef struct palindrome {
    char word[51];
    int is_palindrome;
} Palindrome;

void reverse_string(char *str, int start, int end) {
    char temp;

    // Reverse a substring of a string
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *word) {
    int length = strlen(word);
    if (length <= 1) {
        return 1;
    }

    reverse_string(word, 0, length - 1);

    // Compare the first and last characters and continue
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0;
        }
    }

    return 1;
}

void print_palindrome(Palindrome *palindrome) {
    if (palindrome->is_palindrome) {
        printf("%s is a palindrome.\n", palindrome->word);
    } else {
        printf("%s is not a palindrome.\n", palindrome->word);
    }
}

int main() {
    Palindrome palindromes[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter a word: ");
        scanf("%s", palindromes[i].word);

        palindromes[i].is_palindrome = is_palindrome(palindromes[i].word);
    }

    for (int i = 0; i < 5; i++) {
        print_palindrome(&palindromes[i]);
    }

    return 0;
}