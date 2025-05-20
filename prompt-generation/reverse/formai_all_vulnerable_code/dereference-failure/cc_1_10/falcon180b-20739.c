//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH + 1];
    char *token;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, wordFrequencies[i].word) == 0) {
                    wordFrequencies[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Error: maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(wordFrequencies[numWords].word, token);
                wordFrequencies[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}