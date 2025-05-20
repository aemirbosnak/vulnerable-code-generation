//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int is_delimiter(char c) {
    return isspace(c) || ispunct(c);
}

void add_word(WordFrequency *words, int *word_count, const char *new_word) {
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*word_count].word, new_word);
    words[*word_count].count = 1;
    (*word_count)++;
}

void sort_words(WordFrequency *words, int word_count) {
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (words[i].count < words[j].count) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *words, int word_count) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void process_text_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    WordFrequency words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        char *start = buffer;
        char *end = buffer + strlen(buffer) - 1;

        while (start <= end && is_delimiter(*start)) start++;
        while (end >= start && is_delimiter(*end)) end--;
        
        if (start <= end) {
            *++end = '\0';
            add_word(words, &word_count, start);
        }
    }

    sort_words(words, word_count);
    print_word_frequencies(words, word_count);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_text_file(argv[1]);
    
    return EXIT_SUCCESS;
}