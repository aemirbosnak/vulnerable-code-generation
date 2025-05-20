//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount *wordCounts, int numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords < MAX_WORDS) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
        }
    }
}

void printWords(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    srand(time(NULL));
    int numWords = rand() % MAX_WORDS + 1;
    WordCount wordCounts[MAX_WORDS];

    printf("Enter a filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readWords(file, wordCounts, numWords);
    fclose(file);

    printf("Word counts:\n");
    printWords(wordCounts, numWords);

    return 0;
}