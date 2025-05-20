//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_CONSPIRACY_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char words[MAX_CONSPIRACY_LENGTH];
    int length;
} ConspiracyTheory;

void loadWords(char* filename, WordFrequency* words, int maxWords) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        if (++numWords >= maxWords) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

void generateTheory(ConspiracyTheory* theory, WordFrequency* words, int numWords) {
    srand(time(NULL));

    theory->length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    for (int i = 0; i < theory->length; ++i) {
        int wordIndex = rand() % numWords;
        strncpy(theory->words[i], words[wordIndex].word, MAX_WORD_LENGTH);
    }
    theory->words[theory->length] = '\0';
}

void printTheory(const ConspiracyTheory* theory) {
    printf("Theory: %s\n", theory->words);
}

int main() {
    WordFrequency words[MAX_WORDS];
    loadWords("words.txt", words, MAX_WORDS);

    ConspiracyTheory theory;
    generateTheory(&theory, words, MAX_WORDS);

    printTheory(&theory);

    return 0;
}