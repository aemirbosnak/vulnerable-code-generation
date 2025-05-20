//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A structure to store a word and its frequency
typedef struct {
    char *word;
    int frequency;
} WordFrequency;

// A function to compare two words by their frequency
int compareWordFrequency(const void *a, const void *b) {
    const WordFrequency *wa = (const WordFrequency *)a;
    const WordFrequency *wb = (const WordFrequency *)b;
    return wb->frequency - wa->frequency;
}

// A function to count the frequency of each word in a string
void countWordFrequencies(char *string, WordFrequency **words, int *numWords) {
    // Tokenize the string into words
    char *token = strtok(string, " ");
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(words[i]->word, token) == 0) {
                words[i]->frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            words[*numWords] = (WordFrequency *)malloc(sizeof(WordFrequency));
            words[*numWords]->word = strdup(token);
            words[*numWords]->frequency = 1;
            (*numWords)++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }
}

// A function to print the top N words in a string
void printTopWords(WordFrequency **words, int numWords, int N) {
    // Sort the words by their frequency
    qsort(words, numWords, sizeof(WordFrequency *), compareWordFrequency);

    // Print the top N words
    for (int i = 0; i < N; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }
}

int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Count the frequency of each word in the string
    WordFrequency *words[1000];
    int numWords = 0;
    countWordFrequencies(string, words, &numWords);

    // Print the top 10 words in the string
    printTopWords(words, numWords, 10);

    // Free the memory allocated for the words
    for (int i = 0; i < numWords; i++) {
        free(words[i]->word);
        free(words[i]);
    }

    return 0;
}