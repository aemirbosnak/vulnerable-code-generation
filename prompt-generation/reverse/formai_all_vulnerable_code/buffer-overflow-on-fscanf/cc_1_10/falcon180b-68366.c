//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char fileName[MAX_WORD_LENGTH];
    FILE *fp;
    Word words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the file to be checked: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fscanf(fp, "%s", input)!= EOF) {
        if (strlen(input) > 0) {
            numWords++;
            if (numWords > MAX_WORDS) {
                printf("Error: Too many words\n");
                exit(1);
            }
            strcpy(words[numWords-1].word, input);
            words[numWords-1].count = 1;
        }
    }

    fclose(fp);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Words in file:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    return 0;
}