//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadWords(char* filename, WordFrequency words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
    }

    fclose(file);

    for (int i = 0; i < numWords; i++) {
        words[i].frequency = 0;
    }
}

void analyzeText(char* text, WordFrequency words[]) {
    char* token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int wordIndex = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex >= 0) {
            words[wordIndex].frequency++;
        } else {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void printTopWords(WordFrequency words[], int numWords) {
    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    srand(time(NULL));

    char* filename = "words.txt";
    WordFrequency words[MAX_WORDS];

    loadWords(filename, words);

    char* text = "In a dystopian future, hackers rule the world. They manipulate data, control machines, and even people's minds through their advanced technology. The government tries to suppress them, but they always find a way to stay one step ahead.";

    analyzeText(text, words);

    int numTopWords = 10;
    printTopWords(words, numTopWords);

    return 0;
}