//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *inputFile, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }

    *numWords = i;
}

void sortWords(WordFrequency *words, int numWords) {
    int i, j;
    WordFrequency temp;

    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (words[j].frequency > words[i].frequency) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency *words, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

void generateCode(WordFrequency *words, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("\"%s\" %d;\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char **argv) {
    FILE *inputFile;
    WordFrequency words[MAX_WORDS];
    int numWords;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    readWords(inputFile, words, &numWords);
    fclose(inputFile);

    sortWords(words, numWords);
    printWords(words, numWords);
    generateCode(words, numWords);

    return 0;
}