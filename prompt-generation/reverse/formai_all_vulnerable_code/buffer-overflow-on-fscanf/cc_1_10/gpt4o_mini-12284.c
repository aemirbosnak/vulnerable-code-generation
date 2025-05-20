//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void add_word(WordFreq *words, int *num_words, const char *word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    
    strcpy(words[*num_words].word, word);
    words[*num_words].count = 1;
    (*num_words)++;
}

int compare(const void *a, const void *b) {
    return ((WordFreq *)b)->count - ((WordFreq *)a)->count;
}

void print_summary(WordFreq *words, int num_words, int summary_length) {
    printf("Summary (Top %d words):\n", summary_length);
    for (int i = 0; i < summary_length && i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void summarize_text(const char *filename, int summary_length) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    WordFreq words[MAX_WORDS];
    int num_words = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        add_word(words, &num_words, buffer);
    }
    
    fclose(file);

    qsort(words, num_words, sizeof(WordFreq), compare);
    print_summary(words, num_words, summary_length);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <summary_length>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int summary_length = atoi(argv[2]);

    summarize_text(filename, summary_length);

    return 0;
}