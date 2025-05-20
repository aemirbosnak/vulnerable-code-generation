//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// A function to compare two WordCount structs
int compareWordCount(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

// A function to print a WordCount struct
void printWordCount(WordCount *wc) {
    printf("%s: %d\n", wc->word, wc->count);
}

// A function to count the words in a string
WordCount *countWords(char *str) {
    // Split the string into words
    char **words = malloc(sizeof(char *) * 100);
    int numWords = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Count the number of times each word appears
    WordCount *wordCounts = malloc(sizeof(WordCount) * numWords);
    for (int i = 0; i < numWords; i++) {
        wordCounts[i].word = words[i];
        wordCounts[i].count = 0;
    }
    for (int i = 0; i < numWords; i++) {
        for (int j = 0; j < numWords; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count++;
            }
        }
    }

    // Sort the word counts in alphabetical order
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCount);

    // Return the word counts
    return wordCounts;
}

int main() {
    // Get the input string from the user
    char *str = malloc(sizeof(char) * 100);
    printf("Enter a string: ");
    gets(str);

    // Count the words in the string
    WordCount *wordCounts = countWords(str);

    // Print the word counts
    printf("Word counts:\n");
    for (int i = 0; i < 100; i++) {
        if (wordCounts[i].word != NULL) {
            printWordCount(&wordCounts[i]);
        }
    }

    // Free the memory allocated for the string and the word counts
    free(str);
    free(wordCounts);

    return 0;
}