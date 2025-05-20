//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
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
        str[i] = tolower((unsigned char)str[i]);
    }
}

int compare(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

void add_word(WordCount *words, int *word_count, const char *new_word) {
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }

    // If the word is not found, add it new
    strcpy(words[*word_count].word, new_word);
    words[*word_count].count = 1;
    (*word_count)++;
}

void print_word_counts(WordCount *words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer); // Normalize to lowercase
        // Remove punctuation from the word
        int len = strlen(buffer);
        char cleaned_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (isalnum((unsigned char)buffer[i])) {
                cleaned_word[j++] = buffer[i];
            }
        }
        cleaned_word[j] = '\0'; // Null terminate cleaned_word
        if (j > 0) { // Avoid adding empty words
            add_word(words, &word_count, cleaned_word);
        }
    }

    fclose(file);

    qsort(words, word_count, sizeof(WordCount), compare);
    print_word_counts(words, word_count);

    return 0;
}