//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency, int *word_count) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word_frequency[i].word[i] = tolower(ch);
            i++;
        } else if (i > 0) {
            word_frequency[i - 1].frequency++;
            i = 0;
        }
    }
    if (i > 0) {
        word_frequency[i - 1].frequency++;
    }
    *word_count = i;
}

void sort_word_frequency(WordFrequency *word_frequency, int word_count) {
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (word_frequency[j].frequency > word_frequency[i].frequency) {
                WordFrequency temp = word_frequency[i];
                word_frequency[i] = word_frequency[j];
                word_frequency[j] = temp;
            }
        }
    }
}

void print_word_frequency(WordFrequency *word_frequency, int word_count) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    WordFrequency word_frequency[MAX_WORDS];
    int word_count = 0;

    read_file(file, word_frequency, &word_count);
    fclose(file);

    sort_word_frequency(word_frequency, word_count);
    print_word_frequency(word_frequency, word_count);

    return 0;
}