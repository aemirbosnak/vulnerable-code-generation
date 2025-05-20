//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_MAX_LENGTH 50

typedef struct {
    char word[WORD_MAX_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int wordCount = 0;
    char word[WORD_MAX_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        strcpy(words[wordCount].word, word);
        words[wordCount].frequency = 1;
        wordCount++;
    }

    fclose(file);
}

void countFrequencies(WordFrequency* words, int numWords) {
    int i, j;
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printFrequencies(WordFrequency* words, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    readWords(argv[1], words);
    countFrequencies(words, MAX_WORDS);
    printFrequencies(words, MAX_WORDS);

    return 0;
}