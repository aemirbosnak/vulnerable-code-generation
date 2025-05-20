//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void initialize_word_frequency(WordFrequency *word_frequency, char *word) {
    strcpy(word_frequency->word, word);
    word_frequency->frequency = 0;
}

int compare_word_frequency(const void *a, const void *b) {
    WordFrequency *word_frequency_a = (WordFrequency *) a;
    WordFrequency *word_frequency_b = (WordFrequency *) b;

    return strcmp(word_frequency_a->word, word_frequency_b->word);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency word_frequency_table[MAX_NUM_WORDS];
    int num_words = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_NUM_WORDS) {
            fprintf(stderr, "Reached maximum number of words.\n");
            exit(1);
        }

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_frequency_table[i].word) == 0) {
                word_frequency_table[i].frequency++;
                break;
            }
        }

        if (i == num_words) {
            initialize_word_frequency(&word_frequency_table[num_words], word);
            num_words++;
        }
    }

    qsort(word_frequency_table, num_words, sizeof(WordFrequency), compare_word_frequency);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    fclose(file);
    return 0;
}