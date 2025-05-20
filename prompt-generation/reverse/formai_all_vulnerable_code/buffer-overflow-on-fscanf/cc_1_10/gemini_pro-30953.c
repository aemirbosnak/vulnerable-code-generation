//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compare_word_frequencies(const void *a, const void *b) {
    const WordFrequency *wfa = (const WordFrequency *)a;
    const WordFrequency *wfb = (const WordFrequency *)b;
    return strcmp(wfa->word, wfb->word);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_frequencies[i].word) == 0) {
                word_frequencies[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_frequencies[num_words].word = strdup(word);
            word_frequencies[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    qsort(word_frequencies, num_words, sizeof(WordFrequency), compare_word_frequencies);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(word_frequencies[i].word);
    }

    return 0;
}