//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

void countWords(char *filename, WordCount *wordCounts, int numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            WordCount newWordCount;
            newWordCount.word = word;
            newWordCount.count = 1;
            wordCounts = realloc(wordCounts, sizeof(WordCount) * (numWords + 1));
            wordCounts[numWords] = newWordCount;
            numWords++;
        }
    }

    fclose(file);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    countWords(argv[1], wordCounts, numWords);
    printWordCounts(wordCounts, numWords);

    return 0;
}