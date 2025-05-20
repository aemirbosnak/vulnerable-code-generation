//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }
}

void countWords(char words[MAX_WORDS][MAX_WORD_LENGTH], int counts[MAX_WORDS]) {
    int i, j;

    for (i = 0; i < MAX_WORDS; i++) {
        counts[i] = 0;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                counts[i]++;
                break;
            }
        }
    }
}

void printFrequencies(WordFrequency freq[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (freq[i].count > 0) {
            printf("%s: %d\n", freq[i].word, freq[i].count);
        }
    }
}

int main() {
    FILE *file;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency freq[MAX_WORDS];
    int counts[MAX_WORDS];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readWords(file, words);

    countWords(words, counts);

    for (int i = 0; i < MAX_WORDS; i++) {
        strcpy(freq[i].word, words[i]);
        freq[i].count = counts[i];
    }

    printFrequencies(freq);

    fclose(file);

    return 0;
}