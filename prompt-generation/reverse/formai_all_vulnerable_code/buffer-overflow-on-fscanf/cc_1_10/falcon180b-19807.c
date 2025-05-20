//Falcon-180B DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char *filename, WordCount *wordCounts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        wordCounts[index].count++;
    }

    fclose(file);
}

int hash(char *word) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_WORDS;
}

void printTopWords(WordCount *wordCounts, int numWords) {
    printf("Top %d most frequent words:\n", numWords);
    int i;
    for (i = 0; i < numWords && i < MAX_WORDS; i++) {
        if (wordCounts[i].count == 0) {
            break;
        }
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    WordCount wordCounts[MAX_WORDS];
    memset(wordCounts, 0, sizeof(wordCounts));

    readWords(argv[1], wordCounts);

    int numWords = 0;
    while (numWords < MAX_WORDS && wordCounts[numWords].count == 0) {
        numWords++;
    }

    printTopWords(wordCounts, numWords);

    return 0;
}