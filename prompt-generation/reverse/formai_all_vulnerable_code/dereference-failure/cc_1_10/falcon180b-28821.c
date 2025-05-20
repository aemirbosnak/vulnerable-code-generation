//Falcon-180B DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char word[100];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void countWords(char *filename, WordCount *wordCounts, int numWords) {
    FILE *fp = fopen(filename, "r");
    char line[1000];
    char *word;
    int i = 0;

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i < numWords) {
                strncpy(wordCounts[i].word, word, strlen(word));
                wordCounts[i].count = 1;
                i++;
            } else {
                printf("Too many words in file.\n");
                exit(1);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compare);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (numWords < MAX_WORDS && numWords < argc - 1) {
        strcpy(wordCounts[numWords].word, argv[numWords + 1]);
        numWords++;
    }

    countWords(filename, wordCounts, numWords);

    return 0;
}