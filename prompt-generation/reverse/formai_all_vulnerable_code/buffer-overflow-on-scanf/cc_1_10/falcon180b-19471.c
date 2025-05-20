//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char input[1000];
    FILE *file;
    WordCount wordCounts[100];
    int numWords = 0;

    printf("Enter the name of the file to count words in: ");
    scanf("%s", input);

    file = fopen(input, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    char *token;
    while ((token = strtok(NULL, " \t\n\r\f\v"))!= NULL) {
        strcpy(word, token);

        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    printWordCounts(wordCounts, numWords);

    return 0;
}