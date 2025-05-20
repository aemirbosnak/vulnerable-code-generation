//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000000
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequencyPair;

void read_file(FILE *file, char *word) {
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        } else {
            word[i] = '\0';
        }
    }
}

void count_word_frequency(char *word, WordFrequencyPair *word_frequency_pairs, int num_word_frequency_pairs) {
    int i;
    for (i = 0; i < num_word_frequency_pairs; i++) {
        if (strcmp(word, word_frequency_pairs[i].word) == 0) {
            word_frequency_pairs[i].frequency++;
            return;
        }
    }
    if (num_word_frequency_pairs >= MAX_NUM_WORDS) {
        return;
    }
    strcpy(word_frequency_pairs[num_word_frequency_pairs].word, word);
    word_frequency_pairs[num_word_frequency_pairs].frequency = 1;
    num_word_frequency_pairs++;
}

void print_word_frequency(WordFrequencyPair *word_frequency_pairs, int num_word_frequency_pairs) {
    int i;
    for (i = 0; i < num_word_frequency_pairs; i++) {
        printf("%s: %d\n", word_frequency_pairs[i].word, word_frequency_pairs[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordFrequencyPair word_frequency_pairs[MAX_NUM_WORDS];
    int num_word_frequency_pairs = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            count_word_frequency(word, word_frequency_pairs, num_word_frequency_pairs);
        }
    }

    fclose(file);

    print_word_frequency(word_frequency_pairs, num_word_frequency_pairs);

    return 0;
}