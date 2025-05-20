//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int isValidWord(char* word) {
    int length = strlen(word);

    if (length == 0 || length > MAX_WORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (isValidWord(word)) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (numWords >= MAX_WORD_LENGTH) {
                printf("Maximum number of words reached.\n");
                break;
            }

            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}