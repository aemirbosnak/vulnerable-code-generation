//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_punctuation(char c) {
    return (c == '.' || c == ',' || c == ';' || c == ' ' || c == '?' || c == '!' || c == '"');
}

void count_words(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Convert word to lowercase
        to_lowercase(word);

        // Remove punctuation from the word
        size_t len = strlen(word);
        for (size_t j = 0; j < len; j++) {
            if (is_punctuation(word[j])) {
                memmove(&word[j], &word[j + 1], len - j);
                len--;
                j--;
            }
        }

        // Check if the word is new or increment its count
        int found = 0;
        for (int i = 0; i < *wordCountSize; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found && *wordCountSize < MAX_WORDS) {
            strcpy(wordCounts[*wordCountSize].word, word);
            wordCounts[*wordCountSize].count = 1;
            (*wordCountSize)++;
        }
    }

    fclose(file);
}

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void print_word_counts(WordCount *wordCounts, int wordCountSize) {
    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordCount wordCounts[MAX_WORDS];
    int wordCountSize = 0;

    count_words(argv[1], wordCounts, &wordCountSize);

    // Sort the word counts in descending order
    qsort(wordCounts, wordCountSize, sizeof(WordCount), compare);

    // Print the sorted word counts
    print_word_counts(wordCounts, wordCountSize);

    return EXIT_SUCCESS;
}