//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency *wordFrequencies = malloc(sizeof(WordFrequency) * MAX_WORDS);
    if (wordFrequencies == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            fclose(file);
            free(wordFrequencies);
            return 1;
        }

        word[strcspn(word, ".,!?;:\"'\"")] = '\0';
        word[strcspn(word, "0123456789")] = '\0';

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    return 0;
}