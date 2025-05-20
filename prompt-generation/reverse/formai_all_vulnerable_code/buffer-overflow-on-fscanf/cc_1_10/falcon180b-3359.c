//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCountPair;

int compareWords(const void *a, const void *b) {
    WordCountPair *wordA = (WordCountPair *)a;
    WordCountPair *wordB = (WordCountPair *)b;
    return strcmp(wordA->word, wordB->word);
}

void countWords(char *filename, WordCountPair *wordCounts, int numWordCounts) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int numWords = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        wordLength = strlen(word);
        if (wordLength > 0 && isalpha(word[0])) { // ignore non-alpha characters
            for (int i = 0; i < numWordCounts; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (numWords < numWordCounts) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);
    qsort(wordCounts, numWordCounts, sizeof(WordCountPair), compareWords);
}

void printWordCounts(WordCountPair *wordCounts, int numWordCounts) {
    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCountPair wordCounts[MAX_WORD_LENGTH];
    int numWordCounts = 0;

    countWords(argv[1], wordCounts, numWordCounts);
    printWordCounts(wordCounts, numWordCounts);

    return 0;
}