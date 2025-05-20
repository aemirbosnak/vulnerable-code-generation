//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000 // Maximum number of unique words
#define MAX_WORD_LENGTH 50 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *inputFile;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        numWords = 0;
        wordLength = 0;
        memset(word, 0, sizeof(word));
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word[wordLength++] = tolower(line[i]);
            } else {
                if (wordLength > 0) {
                    word[wordLength] = '\0';
                    if (numWords < MAX_WORDS) {
                        strcpy(wordFrequencies[numWords].word, word);
                        wordFrequencies[numWords].frequency = 1;
                        numWords++;
                    }
                }
                wordLength = 0;
            }
        }
        if (wordLength > 0) {
            word[wordLength] = '\0';
            if (numWords < MAX_WORDS) {
                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}