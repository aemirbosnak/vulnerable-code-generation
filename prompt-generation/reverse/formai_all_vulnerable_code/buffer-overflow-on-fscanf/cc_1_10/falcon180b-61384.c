//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Maximum number of words reached: %d\n", MAX_WORDS);
            break;
        }
        words[*numWords].word[0] = toupper(word[0]);
        strcpy(&words[*numWords].word[1], &word[1]);
        words[*numWords].count = 1;
        (*numWords)++;
    }

    fclose(file);
}

void spellCheck(char *filename, WordFrequency *words, int numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                break;
            }
        }

        if (i == numWords) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(argv[1], words, &numWords);

    spellCheck(argv[2], words, numWords);

    return 0;
}