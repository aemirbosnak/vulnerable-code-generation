//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000000 // maximum number of words to process
#define MAX_WORD_LENGTH 100 // maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare_word_frequency(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;

    if (word1->count > word2->count) {
        return -1;
    } else if (word1->count < word2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *input_file;
    char input_buffer[MAX_WORD_LENGTH];
    WordFrequency word_frequency_table[MAX_WORDS];
    int num_words = 0;
    int i;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(input_file, "%s", input_buffer)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            return 1;
        }

        int word_length = strlen(input_buffer);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            return 1;
        }

        strcpy(word_frequency_table[num_words].word, input_buffer);
        word_frequency_table[num_words].count = 1;
        num_words++;
    }

    fclose(input_file);

    qsort(word_frequency_table, num_words, sizeof(WordFrequency), compare_word_frequency);

    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].count);
    }

    return 0;
}