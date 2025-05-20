//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: light-weight
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
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached\n");
            break;
        }
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, input) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(fp);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}