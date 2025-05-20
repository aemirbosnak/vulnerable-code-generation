//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 20

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *w1 = (WordCount *)a;
    WordCount *w2 = (WordCount *)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *fp;
    char line[MAX_LENGTH];
    char *token;
    char *movieTitle = NULL;
    int numWords = 0;
    WordCount *wordCounts = NULL;

    printf("Enter the name of the text file: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            if (movieTitle == NULL) {
                movieTitle = strdup(token);
            } else {
                WordCount *newWordCount = malloc(sizeof(WordCount));
                strcpy(newWordCount->word, token);
                newWordCount->count = 1;
                wordCounts = realloc(wordCounts, (numWords + 1) * sizeof(WordCount));
                wordCounts[numWords] = *newWordCount;
                free(newWordCount);
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    if (movieTitle == NULL) {
        printf("Error: no movie title found.\n");
        exit(1);
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Movie title: %s\n", movieTitle);
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}