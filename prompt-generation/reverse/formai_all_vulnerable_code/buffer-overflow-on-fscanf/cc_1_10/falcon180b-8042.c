//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void readWords(FILE *fp, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        WordFrequency *wf = wordFrequencies;
        while (wf->word!= NULL) {
            if (strcmp(word, wf->word) == 0) {
                wf->frequency++;
                break;
            }
            wf++;
        }
        if (wf->word == NULL) {
            wf->word = strdup(word);
            wf->frequency = 1;
        }
    }
}

void printWordFrequencies(WordFrequency *wordFrequencies) {
    WordFrequency *wf = wordFrequencies;
    while (wf->word!= NULL) {
        printf("%s: %d\n", wf->word, wf->frequency);
        wf++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: failed to open file '%s'\n", argv[1]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readWords(fp, wordFrequencies);
    fclose(fp);

    printWordFrequencies(wordFrequencies);

    return 0;
}