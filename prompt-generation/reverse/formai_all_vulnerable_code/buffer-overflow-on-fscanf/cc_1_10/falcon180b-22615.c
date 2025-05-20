//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    // Initialize all word frequencies to zero
    WordFrequency wordFrequencies[MAX_WORDS] = {{0}};

    // Open input file
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read in words from the input file
    while (fscanf(inputFile, "%s", line)!= EOF) {
        // Convert line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize the line into words
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            // Check if the word is already in the frequency table
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(wordFrequencies[i].word, token) == 0) {
                    wordFrequencies[i].count++;
                    found = 1;
                    break;
                }
            }

            // If the word is not in the frequency table, add it
            if (!found) {
                strcpy(wordFrequencies[wordCount].word, token);
                wordFrequencies[wordCount].count = 1;
                wordCount++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    // Sort the frequency table alphabetically
    qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWords);

    // Print the frequency table
    printf("Word Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}