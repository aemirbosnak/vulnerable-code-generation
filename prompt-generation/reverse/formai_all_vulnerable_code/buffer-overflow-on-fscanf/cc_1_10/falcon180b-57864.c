//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: too many unique words in file\n");
            fclose(file);
            return 1;
        }

        WordCount* foundWord = NULL;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                foundWord = &words[i];
                break;
            }
        }

        if (foundWord == NULL) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        } else {
            foundWord->count++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}