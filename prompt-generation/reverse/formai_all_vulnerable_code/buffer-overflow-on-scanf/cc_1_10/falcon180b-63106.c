//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
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
    FILE *fp;
    char filename[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached!\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);

    return 0;
}