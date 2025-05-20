//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct WordFrequency *w1 = (struct WordFrequency *)a;
    struct WordFrequency *w2 = (struct WordFrequency *)b;

    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *inputFile;
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int i, j;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read input file
    struct WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(struct WordFrequency));
    int numWords = 0;

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word[0] = tolower(line[i]);
                wordLength = 1;

                while (i < strlen(line) && isalpha(line[i])) {
                    strcat(word, &line[i]);
                    i++;
                    wordLength++;
                }

                if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
                    for (j = 0; j < numWords; j++) {
                        if (strcmp(wordFrequencies[j].word, word) == 0) {
                            wordFrequencies[j].frequency++;
                            break;
                        }
                    }

                    if (j == numWords) {
                        strcpy(wordFrequencies[numWords].word, word);
                        wordFrequencies[numWords].frequency = 1;
                        numWords++;

                        if (numWords == MAX_WORDS) {
                            printf("Warning: maximum number of words reached.\n");
                            break;
                        }
                    }
                }
            }
        }
    }

    fclose(inputFile);

    // Sort words by frequency
    qsort(wordFrequencies, numWords, sizeof(struct WordFrequency), compareWords);

    // Print word frequencies
    printf("Word frequencies:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);

    return 0;
}