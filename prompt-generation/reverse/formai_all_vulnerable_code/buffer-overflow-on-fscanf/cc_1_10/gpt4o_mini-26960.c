//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int find_word(char *word, WordCount *word_counts, int total_words) {
    for (int i = 0; i < total_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(char *word, WordCount *word_counts, int *total_words) {
    int index = find_word(word, word_counts, *total_words);
    if (index == -1) {
        // New word found, add it to list
        strcpy(word_counts[*total_words].word, word);
        word_counts[*total_words].count = 1;
        (*total_words)++;
    } else {
        // Increment the count of the existing word
        word_counts[index].count++;
    }
}

void display_word_counts(WordCount *word_counts, int total_words) {
    printf("\n*** Word Frequency in the Post-Apocalyptic World ***\n");
    for (int i = 0; i < total_words; i++) {
        printf("Word: '%s' - Count: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    WordCount word_counts[MAX_WORDS];
    int total_words = 0;
    char word[MAX_WORD_LENGTH];

    // Read words from file
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word); // Normalize case
        add_word(word, word_counts, &total_words);
    }

    fclose(file);

    display_word_counts(word_counts, total_words);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    
    printf("\nThe wasteland whispers stories of survival, and each word counts.\n");

    return EXIT_SUCCESS;
}