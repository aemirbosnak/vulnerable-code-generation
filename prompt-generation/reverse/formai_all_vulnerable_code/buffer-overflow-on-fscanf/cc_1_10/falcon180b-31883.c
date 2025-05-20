//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void generateSentence(char *sentence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        sentence[i] = toupper(rand() % 26 + 'A');
    }
    sentence[length] = '\0';
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    srand(time(NULL));

    char *words[MAX_WORDS];
    int numWords = 0;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char word[MAX_SENTENCE_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            fclose(inputFile);
            return 1;
        }
        words[numWords] = strdup(word);
        numWords++;
    }
    fclose(inputFile);

    qsort(words, numWords, sizeof(char *), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], 1);
    }

    return 0;
}