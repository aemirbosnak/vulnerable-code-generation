//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALPHABET_SIZE 26

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void generateRandomWord(char* word) {
    int length = rand() % MAX_WORD_LENGTH + 1;
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % ALPHABET_SIZE;
    }
    word[length] = '\0';
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* w1 = (const WordFrequency*)a;
    const WordFrequency* w2 = (const WordFrequency*)b;
    return strcmp(w1->word, w2->word);
}

void printWordFrequencyTable(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    srand(time(NULL));

    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            fclose(inputFile);
            return 2;
        }
        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }

    fclose(inputFile);

    for (int i = 0; i < numWords; i++) {
        int index = i;
        while (index > 0 && words[index - 1].frequency < words[index].frequency) {
            WordFrequency temp = words[index];
            words[index] = words[index - 1];
            words[index - 1] = temp;
            index--;
        }
    }

    printf("Sorted word frequency table:\n");
    printWordFrequencyTable(words, numWords);

    return 0;
}