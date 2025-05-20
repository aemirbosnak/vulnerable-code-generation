//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_words(char *filename, WordFrequency *word_frequency, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (word_length >= MAX_WORD_LENGTH) {
            printf("Error: Word \"%s\" is too long\n", word);
            exit(1);
        }
        strcpy(word_frequency[*num_words].word, word);
        word_frequency[*num_words].count = 1;
        (*num_words)++;
    }

    fclose(file);
}

void print_word_frequency(WordFrequency *word_frequency, int num_words) {
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency word_frequency[MAX_WORDS];
    int num_words = 0;

    read_words(filename, word_frequency, &num_words);
    print_word_frequency(word_frequency, num_words);

    return 0;
}