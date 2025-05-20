//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void clean_word(char *word) {
    char clean[MAX_WORD_LENGTH] = {0};
    int j = 0;

    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) {
            clean[j++] = word[i];
        } else {
            if (j > 0) break; // break on first non-alpha, consider the current word finished
        }
    }
    clean[j] = '\0';
    strcpy(word, clean);
}

void add_word(WordCount *wordCounts, int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }

    strcpy(wordCounts[*size].word, word);
    wordCounts[*size].count = 1;
    (*size)++;
}

void print_word_counts(WordCount *wordCounts, int size) {
    printf("\nCheerful Word Frequency Counter Results 🎉:\n");
    for (int i = 0; i < size; i++) {
        printf("Word: '%s' | Count: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Hello there! Welcome to the Cheerful Word Frequency Counter! 🌈\n");
    printf("Please enter the name of the text file you want to analyze (e.g. 'text.txt'): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oops! It seems we cannot find the file \"%s\". Please check the name and try again! 😊\n", filename);
        return 1;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    char word[MAX_WORD_LENGTH];
    int size = 0;

    printf("Yay! We're reading the file \"%s\" now...\n", filename);
    while (fscanf(file, "%s", word) == 1) {
        clean_word(word);
        if (strlen(word) > 0) {
            to_lower_case(word);
            add_word(wordCounts, &size, word);
        }
    }

    fclose(file);

    print_word_counts(wordCounts, size);
    printf("\nThank you for using the Cheerful Word Frequency Counter! Have a fantastic day! 🌟\n");
    return 0;
}