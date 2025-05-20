//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE *file, WordFrequency *words) {
    char word[WORD_LEN];
    int wordLen = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        if (wordLen >= MAX_WORDS) {
            break;
        }

        if (strlen(word) > 0 &&!isalpha(word[0])) {
            continue;
        }

        strcpy(words[wordLen].word, word);
        words[wordLen].frequency++;
        wordLen++;
    }
}

void sortWords(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, words);
    fclose(file);

    sortWords(words, numWords);
    printWords(words, numWords);

    return 0;
}