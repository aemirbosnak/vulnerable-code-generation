//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[100];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }

        words[i].word = strdup(word);
        words[i].frequency = 1;
        i++;
    }
}

void countWords(WordFrequency words[MAX_WORDS]) {
    int i, j;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    readWords(file, words);
    countWords(words);
    printWords(words);

    fclose(file);

    return 0;
}