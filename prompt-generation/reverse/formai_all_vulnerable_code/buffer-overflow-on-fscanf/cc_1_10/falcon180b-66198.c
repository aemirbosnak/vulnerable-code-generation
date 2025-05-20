//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE* file, WordFrequency* frequencies) {
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        count++;
        frequencies[count].word[strcspn(word, "\n")] = '\0'; // Remove newline character
        strcpy(frequencies[count].word, word);
        frequencies[count].count = 0;
    }
    frequencies[count].word[0] = '\0'; // Set last frequency to empty string
}

void generateAlienLanguage(WordFrequency* frequencies, int numWords) {
    char* words[MAX_WORDS];
    int i, j, k;

    // Fill words array with most frequent words
    for (i = 0; i < numWords; i++) {
        for (j = 0; j < i; j++) {
            if (frequencies[j].count < frequencies[i].count) {
                WordFrequency temp = frequencies[j];
                frequencies[j] = frequencies[i];
                frequencies[i] = temp;
            }
        }
        words[i] = frequencies[i].word;
    }

    // Generate alien language
    for (i = 0; i < MAX_WORDS - numWords; i++) {
        int rnd = rand() % numWords;
        strcpy(words[numWords + i], words[rnd]);
    }

    // Print alien language
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    FILE* file;
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    // Open input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file and count word frequencies
    readFile(file, frequencies);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].word[0]!= '\0') {
            numWords++;
        }
    }

    // Generate alien language
    generateAlienLanguage(frequencies, numWords);

    return 0;
}