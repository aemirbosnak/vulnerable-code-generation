//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int isWord(char *word) {
    int length = strlen(word);

    if (length < MIN_WORD_LENGTH || length > MAX_WORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

void readWords(FILE *file, WordFrequency *words) {
    char word[MAX_WORD_LENGTH + 1];

    while (fscanf(file, "%s", word)!= EOF) {
        if (isWord(word)) {
            strcpy(words->word, word);
            words->frequency++;
        }
    }
}

void writeWords(FILE *file, WordFrequency *words, int count) {
    qsort(words, count, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    readWords(inputFile, words);
    writeWords(outputFile, words, wordCount);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}