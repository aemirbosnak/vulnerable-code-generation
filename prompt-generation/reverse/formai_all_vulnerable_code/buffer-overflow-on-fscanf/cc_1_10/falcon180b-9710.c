//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char **argv) {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    char *token = NULL;
    size_t wordLength = 0;
    while ((fscanf(inputFile, "%s", word))!= EOF) {
        wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: word is too long (%d characters).\n", wordLength);
            exit(1);
        }

        for (int i = 0; i < wordLength; i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }

        token = strtok(word, ",.?!;:");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].frequency++;
            numWords++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}