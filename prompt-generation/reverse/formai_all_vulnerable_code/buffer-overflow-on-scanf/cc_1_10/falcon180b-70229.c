//Falcon-180B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* word1 = (WordFrequency*)a;
    WordFrequency* word2 = (WordFrequency*)b;

    return strcmp(word1->word, word2->word);
}

void readFile(FILE* file, WordFrequency* words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Maximum number of words reached.\n");
        }
    }
}

void printWords(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readFile(file, words);
    fclose(file);

    printWords(words, numWords);

    return 0;
}