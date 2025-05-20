//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;

    return strcmp(w1->word, w2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    file = fopen(input, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fscanf(file, "%s", input)!= EOF) {
        word = strtok(input, ",.?!;:\"'");

        while (word!= NULL) {
            numWords++;

            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }

            strcpy(words[numWords - 1].word, word);
            words[numWords - 1].count = 1;

            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}