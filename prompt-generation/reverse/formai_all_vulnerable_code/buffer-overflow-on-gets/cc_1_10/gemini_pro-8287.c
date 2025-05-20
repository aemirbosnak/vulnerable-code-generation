//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: genius
#include <stdio.h>

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWordFrequency(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf1->count - wf2->count;
}

int main() {
    // Initialize an array of word frequencies
    WordFrequency wordFrequencies[] = {
        { "the", 0 },
        { "of", 0 },
        { "and", 0 },
        { "a", 0 },
        { "to", 0 },
        { "in", 0 },
        { "is", 0 },
        { "you", 0 },
        { "that", 0 },
        { "it", 0 }
    };

    // Read the input text
    char text[10000];
    printf("Enter the text to be analyzed: ");
    gets(text);

    // Tokenize the input text
    char *tokens[1000];
    int numTokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    for (int i = 0; i < numTokens; i++) {
        int found = 0;
        for (int j = 0; j < sizeof(wordFrequencies) / sizeof(WordFrequency); j++) {
            if (strcmp(tokens[i], wordFrequencies[j].word) == 0) {
                wordFrequencies[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordFrequencies[sizeof(wordFrequencies) / sizeof(WordFrequency) - 1].word = tokens[i];
            wordFrequencies[sizeof(wordFrequencies) / sizeof(WordFrequency) - 1].count = 1;
        }
    }

    // Sort the word frequencies in descending order
    qsort(wordFrequencies, sizeof(wordFrequencies) / sizeof(WordFrequency), sizeof(WordFrequency), compareWordFrequency);

    // Print the word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < sizeof(wordFrequencies) / sizeof(WordFrequency); i++) {
        if (wordFrequencies[i].count == 0) {
            break;
        }
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}