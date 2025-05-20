//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputLine[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;
    WordFrequency *wordFrequencies = malloc(MAX_NUM_WORDS * sizeof(WordFrequency));

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(inputLine, MAX_WORD_LENGTH, inputFile)!= NULL) {
        word = strtok(inputLine, " ");
        while (word!= NULL) {
            numWords++;

            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords == MAX_NUM_WORDS) {
                    printf("Error: too many unique words\n");
                    exit(1);
                }

                wordFrequencies[numWords].word = strdup(word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }

            word = strtok(NULL, " ");
        }
    }

    // Sort word frequencies by frequency
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequencies
    printf("Word Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    // Close input file
    fclose(inputFile);

    // Free memory
    for (int i = 0; i < numWords; i++) {
        free(wordFrequencies[i].word);
    }
    free(wordFrequencies);

    return 0;
}