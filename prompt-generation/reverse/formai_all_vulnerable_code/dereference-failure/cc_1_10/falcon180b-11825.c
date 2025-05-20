//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *w1, const void *w2) {
    return strcmp(*(char **)w1, *(char **)w2);
}

void readWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            int i;
            for (i = 0; i < *numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == *numWords) {
                words[*numWords].word[0] = tolower(word[0]);
                strcpy(words[*numWords].word + 1, word + 1);
                words[*numWords].count = 1;
                (*numWords)++;
            }
        }
    }

    fclose(file);
}

void writeWords(char *filename, WordFrequency *words, int numWords) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(input_file, words, &numWords);
    writeWords(output_file, words, numWords);

    return 0;
}