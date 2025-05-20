//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency, int *num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word_frequency[i].word[0] = ch;
            word_frequency[i].word[1] = '\0';
            word_frequency[i].count = 1;
            i++;
        } else if (isdigit(ch)) {
            word_frequency[i - 1].count++;
        }
    }
    *num_words = i;
}

void sort_word_frequency(WordFrequency *word_frequency, int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (word_frequency[j].count > word_frequency[i].count) {
                WordFrequency temp = word_frequency[i];
                word_frequency[i] = word_frequency[j];
                word_frequency[j] = temp;
            }
        }
    }
}

void print_word_frequency(WordFrequency *word_frequency, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s %d\n", word_frequency[i].word, word_frequency[i].count);
    }
}

int main() {
    FILE *file;
    WordFrequency word_frequency[MAX_WORDS];
    int num_words = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    read_file(file, word_frequency, &num_words);

    sort_word_frequency(word_frequency, num_words);

    print_word_frequency(word_frequency, num_words);

    fclose(file);

    return 0;
}