//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    FILE *fp;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    printf("Enter the name of the file to be summarized:\n");
    scanf("%s", input);

    fp = fopen(input, "r");

    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    while (fscanf(fp, "%s", input)!= EOF) {
        word = strtok(input, ",.?!;:");

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Summary:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].count);
    }

    return 0;
}