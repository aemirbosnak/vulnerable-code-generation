//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isPalindrome(char *word);

int main() {
    char word[MAX_LENGTH];
    
    printf("Enter a word to check if it is a Palindrome: ");
    fgets(word, MAX_LENGTH, stdin);

    // Remove newline character from input
    int len = strlen(word);
    if (word[len-1] == '\n') {
        word[len-1] = '\0';
    }

    if (isPalindrome(word)) {
        printf("%s is a Palindrome\n", word);
    } else {
        printf("%s is not a Palindrome\n", word);
    }

    return 0;
}

int isPalindrome(char *word) {
    int start = 0;
    int end = strlen(word) - 1;

    while (start < end) {
        // Ignore non-alphanumeric characters
        while (!isalnum(word[start])) {
            start++;
        }
        while (!isalnum(word[end])) {
            end--;
        }

        // Convert to lowercase for case-insensitive comparison
        char start_char = tolower(word[start]);
        char end_char = tolower(word[end]);

        if (start_char != end_char) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}