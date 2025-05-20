//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordEntry;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordEntry *entryA = (WordEntry *)a;
    WordEntry *entryB = (WordEntry *)b;
    return strcmp(entryA->word, entryB->word);
}

void add_word(WordEntry *words, int *total_words, const char *word) {
    for (int i = 0; i < *total_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    strcpy(words[*total_words].word, word);
    words[*total_words].count = 1;
    (*total_words)++;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    WordEntry words[MAX_WORDS];
    int total_words = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        add_word(words, &total_words, word);
    }

    fclose(file);

    qsort(words, total_words, sizeof(WordEntry), compare);

    // Print results
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < total_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    process_file(argv[1]);
    return 0;
}