//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void* a, const void* b) {
    const struct Word* wordA = (const struct Word*)a;
    const struct Word* wordB = (const struct Word*)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char** argv) {
    FILE* inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (wordLength == MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            fclose(inputFile);
            return 1;
        }

        if (isalpha(word[0])) {
            strcpy(word, toupper(word));
            wordLength++;
        } else {
            word[0] = '\0';
        }

        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (numWords == MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                fclose(inputFile);
                return 1;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(struct Word), compareWords);

    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}