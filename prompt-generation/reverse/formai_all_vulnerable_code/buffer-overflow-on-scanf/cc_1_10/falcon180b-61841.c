//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Maximum number of words exceeded\n");
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        bool found = false;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                found = true;
                break;
            }
        }

        if (!found) {
            strcpy(words[*numWords].word, word);
            words[*numWords].frequency = 1;
            (*numWords)++;
        }
    }

    fclose(file);
}

void printWords(WordFrequency* words, int numWords) {
    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, &numWords);
    printWords(words, numWords);

    return 0;
}