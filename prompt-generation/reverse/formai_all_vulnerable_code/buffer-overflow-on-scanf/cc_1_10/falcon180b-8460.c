//Falcon-180B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void printTopWords(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char line[100];
    char word[MAX_WORD_LEN];
    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        numWords = 0;
        strcpy(word, "");
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcat(word, token);
            strcat(word, " ");
            token = strtok(NULL, ",.?!;:");
            numWords++;
        }
        strcat(word, "\n");

        for (int i = 0; i < numWords; i++) {
            char *token = strtok(word, " ");
            while (token!= NULL) {
                strcpy(wordCounts[i].word, token);
                wordCounts[i].count++;
                token = strtok(NULL, " ");
                i++;
            }
        }
    }

    fclose(file);

    printTopWords(wordCounts, numWords);

    return 0;
}