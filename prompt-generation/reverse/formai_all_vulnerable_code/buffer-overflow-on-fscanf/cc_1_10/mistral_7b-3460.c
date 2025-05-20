//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORD_DELIMITER " \t\n,;.:!?(){}[]"

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Function to read a word from the input stream
void get_word(FILE *fp, char *word, int max_length) {
    int i = 0;
    char c;

    // Skip leading delimiters
    while ((c = fgetc(fp)) != EOF && strchr(WORD_DELIMITER, c) != NULL) {
        // Do nothing
    }

    if (c == EOF) {
        strcpy(word, "");
        return;
    }

    // Read the word, up to the next delimiter or end of file
    word[0] = c;
    for (i = 1; i < max_length && i + 1 < max_length - (int)strlen(WORD_DELIMITER); i++) {
        c = fgetc(fp);
        if (c == EOF || strchr(WORD_DELIMITER, c) != NULL) {
            word[i] = '\0';
            ungetc(c, fp);
            break;
        }
        word[i] = c;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int num_words = 0, num_palindromes = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        num_words++;
        if (is_palindrome(word)) {
            printf("%s ", word);
            num_palindromes++;
        }
    }

    fclose(fp);

    printf("\nTotal words: %d, Palindromic words: %d\n", num_words, num_palindromes);

    return 0;
}