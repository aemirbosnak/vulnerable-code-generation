//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *word_a = (WordFrequency *) a;
    WordFrequency *word_b = (WordFrequency *) b;

    if (word_a->count > word_b->count) {
        return -1;
    } else if (word_a->count < word_b->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[10000];
    char *word;
    int word_count = 0;
    WordFrequency *word_frequency = (WordFrequency *) malloc(MAX_WORDS * sizeof(WordFrequency));

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fgets(line, 10000, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (word_count >= MAX_WORDS) {
                printf("Maximum number of words exceeded\n");
                exit(1);
            }
            strcpy(word_frequency[word_count].word, word);
            word_frequency[word_count].count = 1;
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_frequency, word_count, sizeof(WordFrequency), compare);

    for (int i = 0; i < word_count; i++) {
        printf("%s %d\n", word_frequency[i].word, word_frequency[i].count);
    }

    free(word_frequency);
    fclose(input_file);

    return 0;
}