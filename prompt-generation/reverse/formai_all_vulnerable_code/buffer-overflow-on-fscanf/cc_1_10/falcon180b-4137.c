//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Structure to hold a word and its length
typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

// Function to read words from a file into an array of Word structures
int readWordsFromFile(FILE *file, Word words[]) {
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            return -1;
        }
        strcpy(words[numWords].word, word);
        words[numWords].length = strlen(word);
        numWords++;
    }
    return numWords;
}

// Function to sort an array of Word structures by length
void sortWordsByLength(Word words[], int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].length < words[i].length) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Function to print an array of Word structures
void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int numWords;

    // Open input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return -1;
    }

    // Read words from file
    numWords = readWordsFromFile(file, words);
    if (numWords < 0) {
        fclose(file);
        return numWords;
    }

    // Sort words by length
    sortWordsByLength(words, numWords);

    // Print sorted words
    printf("Sorted words:\n");
    printWords(words, numWords);

    // Close input file
    fclose(file);

    return 0;
}