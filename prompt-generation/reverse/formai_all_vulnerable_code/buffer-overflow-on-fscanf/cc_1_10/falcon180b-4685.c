//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readInput(char* fileName, WordFrequency* wordFrequencies) {
    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    while (fscanf(inputFile, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: word length exceeds maximum limit.\n");
            exit(1);
        }
        int index = hash(word);
        if (index >= 0 && index < MAX_WORDS) {
            wordFrequencies[index].frequency++;
        }
    }

    fclose(inputFile);
}

int hash(char* word) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % MAX_WORDS;
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];

    WordFrequency wordFrequencies[MAX_WORDS];
    readInput(inputFile, wordFrequencies);

    FILE* outputFilePtr = fopen(outputFile, "w");
    if (outputFilePtr == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    printWordFrequencies(wordFrequencies);

    fclose(outputFilePtr);
    return 0;
}