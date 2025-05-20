//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void add_word(WordCount *words, int *word_count, const char *word) {
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*word_count].word, word);
    words[*word_count].count = 1;
    (*word_count)++;
}

void print_word_counts(WordCount *words, int word_count) {
    printf("Word Frequency:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void read_words_from_file(const char *filename, WordCount *words, int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        add_word(words, word_count, word);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;

    read_words_from_file(argv[1], words, &word_count);
    
    qsort(words, word_count, sizeof(WordCount), compare);
    
    print_word_counts(words, word_count);

    return EXIT_SUCCESS;
}