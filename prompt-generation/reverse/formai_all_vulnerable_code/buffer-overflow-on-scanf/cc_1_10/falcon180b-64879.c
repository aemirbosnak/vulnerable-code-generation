//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    char *token;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }

            int len = strlen(token);
            if (len > MAX_WORD_LEN) {
                printf("Error: word '%s' is too long\n", token);
                exit(1);
            }

            words[numWords].word = malloc(len + 1);
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;

            numWords++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}