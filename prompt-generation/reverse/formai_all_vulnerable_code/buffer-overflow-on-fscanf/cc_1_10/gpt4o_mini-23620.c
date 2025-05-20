//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void add_word(WordCount *words, int *num_words, const char *new_word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }

    // Add new word
    strncpy(words[*num_words].word, new_word, MAX_WORD_LENGTH);
    words[*num_words].count = 1;
    (*num_words)++;
}

void read_words(FILE *file, WordCount *words, int *num_words) {
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) == 1) {
        add_word(words, num_words, buffer);
    }
}

void print_word_counts(WordCount *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void free_memory(WordCount *words) {
    // Memory deallocation is not strictly necessary here since we're using stack variables,
    // but if dynamically allocated, would be important
    free(words);
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return;
    }

    WordCount *words = malloc(MAX_WORDS * sizeof(WordCount));
    int num_words = 0;

    read_words(file, words, &num_words);
    fclose(file);

    print_word_counts(words, num_words);
    free_memory(words);
}

void ask_for_file() {
    char filename[256];
    printf("Enter the filename to analyze: ");
    scanf("%s", filename);
    process_file(filename);
}

void prompt_user() {
    char choice;
    printf("Do you want to analyze a file? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        ask_for_file();
    }
}

int main() {
    prompt_user();
    return 0;
}