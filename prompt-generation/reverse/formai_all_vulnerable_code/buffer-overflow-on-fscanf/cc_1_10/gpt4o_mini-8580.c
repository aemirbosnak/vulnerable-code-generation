//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
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

WordCount wc[MAX_WORDS];
int word_count = 0;

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void add_word(const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(wc[i].word, word) == 0) {
            wc[i].count++;
            return;
        }
    }
    strncpy(wc[word_count].word, word, MAX_WORD_LENGTH);
    wc[word_count].count = 1;
    word_count++;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        to_lower(word);
        add_word(word);
    }
    
    fclose(file);
}

void sort_words() {
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (wc[i].count < wc[j].count) {
                WordCount temp = wc[i];
                wc[i] = wc[j];
                wc[j] = temp;
            }
        }
    }
}

void print_word_counts() {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    sort_words();
    print_word_counts();
    
    return EXIT_SUCCESS;
}