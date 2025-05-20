//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 256

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordCountA = (const WordCount *)a;
    const WordCount *wordCountB = (const WordCount *)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v.,!?;:\"'");
        while (token!= NULL) {
            int wordLength = strlen(token);
            if (wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }

            strncpy(wordCounts[numWords].word, token, wordLength);
            wordCounts[numWords].count = 1;
            numWords++;

            if (numWords == MAX_WORD_LENGTH) {
                break;
            }

            token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
        }
    }

    fclose(file);

    printWordCounts(wordCounts, numWords);

    return 0;
}