//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int numWords;
} WordCountTable;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(WordCount *words, int numWords, FILE *file) {
    char word[MAX_SIZE];

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        WordCount newWord;
        strcpy(newWord.word, word);
        newWord.count = 1;

        words[numWords] = newWord;
        numWords++;
    }
}

void printWords(WordCount *words, int numWords) {
    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    WordCountTable table;
    table.words = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    table.numWords = 0;

    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readWords(table.words, table.numWords, file);

    fclose(file);

    printWords(table.words, table.numWords);

    free(table.words);

    return 0;
}