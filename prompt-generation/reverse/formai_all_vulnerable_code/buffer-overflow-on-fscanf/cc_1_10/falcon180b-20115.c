//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
    }

    fclose(file);

    qsort(words, MAX_WORDS, sizeof(WordCount), compareWords);
}

void printWords(WordCount words[], int numWords) {
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char filename[100];
    strcpy(filename, argv[1]);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            numWords++;
        } else {
            break;
        }
    }

    printWords(words, numWords);

    return 0;
}