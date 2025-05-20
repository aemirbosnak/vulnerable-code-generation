//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *fp, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWords(fp, words);

    fclose(fp);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            numWords++;
        }
    }

    printf("Total words: %d\n", numWords);
    printWords(words, numWords);

    return 0;
}