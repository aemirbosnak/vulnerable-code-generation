//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (i < MAX_WORDS) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
            }
        }
    }
}

void spellCheck(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Possible spelling mistake: %s\n", word);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }
    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words);
    fclose(inputFile);
    spellCheck(outputFile, words);
    fclose(outputFile);
    return 0;
}