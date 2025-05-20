//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Convert line to lowercase
        for (i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize line into words
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }

            // Copy word to array
            strcpy(words[numWords].word, token);

            // Increment frequency
            words[numWords].frequency++;

            // Move to next word
            numWords++;

            // Get next token
            token = strtok(NULL, " ");
        }
    }

    // Close file
    fclose(file);

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequency
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}