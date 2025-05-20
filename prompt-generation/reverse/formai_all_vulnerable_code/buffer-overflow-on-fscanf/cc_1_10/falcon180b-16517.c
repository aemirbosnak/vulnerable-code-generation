//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, Word *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char word[100];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: maximum number of words (%d) reached\n", MAX_WORDS);
            exit(1);
        }
        words[*numWords].word = strdup(word);
        words[*numWords].count = 0;
        (*numWords)++;
    }
    fclose(file);
}

void spellCheck(char *filename, Word *words, int numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char line[1000];
    char *word;
    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                printf("Unknown word: %s\n", word);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

void printWords(Word *words, int numWords) {
    qsort(words, numWords, sizeof(Word), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary> <text_file>\n", argv[0]);
        exit(1);
    }
    Word words[MAX_WORDS];
    int numWords = 0;
    readWords(argv[1], words, &numWords);
    spellCheck(argv[2], words, numWords);
    printWords(words, numWords);
    return 0;
}