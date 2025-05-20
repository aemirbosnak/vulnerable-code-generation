//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A structure to store word frequency
typedef struct WordFrequency {
    char* word;
    int frequency;
} WordFrequency;

// A function to compare two word frequencies for sorting
int compareWordFrequency(const void* a, const void* b) {
    const WordFrequency* word1 = (const WordFrequency*)a;
    const WordFrequency* word2 = (const WordFrequency*)b;
    return word2->frequency - word1->frequency;
}

int main() {
    char input[1000], * token;
    int count = 0, i = 0, j = 0, found = 0;
    WordFrequency* frequencies = NULL;

    printf("Enter a text to count the frequency of words:\n");
    fgets(input, sizeof(input), stdin);

    // Convert input to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize input and count word frequency
    token = strtok(input, " \n\t");
    while (token != NULL) {
        found = 0;
        for (i = 0; i < count; i++) {
            if (strcmp(token, frequencies[i].word) == 0) {
                frequencies[i].frequency++;
                found = 1;
                break;
            }
        }
        // Add new word to word frequency array
        if (!found) {
            count++;
            frequencies = (WordFrequency*)realloc(frequencies, count * sizeof(WordFrequency));
            frequencies[count - 1].word = (char*)malloc(strlen(token) + 1);
            strcpy(frequencies[count - 1].word, token);
            frequencies[count - 1].frequency = 1;
        }
        token = strtok(NULL, " \n\t");
    }

    // Sort word frequency array by frequency
    qsort(frequencies, count, sizeof(WordFrequency), compareWordFrequency);

    printf("Frequency of words:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
    }

    // Free word frequency array
    for (i = 0; i < count; i++) {
        free(frequencies[i].word);
    }
    free(frequencies);

    return 0;
}