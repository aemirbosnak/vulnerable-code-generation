//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *inputFile, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            } else if (i == MAX_WORDS - 1) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
                break;
            }
        }
    }
}

void printWords(WordFrequency words[]) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words);
    fclose(inputFile);

    printWords(words);

    return 0;
}