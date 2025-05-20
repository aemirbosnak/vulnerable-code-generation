//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE* file, WordFrequency* frequencies) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        frequencies[i].word[0] = '\0';
        strcat(frequencies[i].word, word);
        frequencies[i].count++;
        i++;
    }
}

void print_frequencies(WordFrequency* frequencies, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (frequencies[i].word[0]!= '\0') {
            printf("%s : %d\n", frequencies[i].word, frequencies[i].count);
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    WordFrequency frequencies[MAX_WORDS];
    read_file(file, frequencies);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].word[0]!= '\0') {
            num_words++;
        }
    }

    print_frequencies(frequencies, num_words);

    fclose(file);
    return 0;
}