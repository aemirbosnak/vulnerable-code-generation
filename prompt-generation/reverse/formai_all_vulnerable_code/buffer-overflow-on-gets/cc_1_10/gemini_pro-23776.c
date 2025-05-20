//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum length of a word
#define MAX_WORD_LENGTH 50

// Defining a structure to represent a word and its count
typedef struct {
    char word[MAX_WORD_LENGTH + 1]; // +1 for the null-terminator
    int count;
} WordCount;

// Function to compare two WordCount structures based on their word field
int compareWordCounts(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

// Function to count the occurrences of each word in a given string
int countWords(const char *str, WordCount *wordCounts) {
    // Tokenizing the string into words using strtok()
    char *token = strtok(str, " ");
    int numWords = 0;

    // Iterating over the words in the string
    while (token != NULL) {
        // Checking if the word is already present in the wordCounts array
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, wordCounts[i].word) == 0) {
                // If the word is found, increment its count
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the wordCounts array
        if (!found) {
            strcpy(wordCounts[numWords].word, token);
            wordCounts[numWords].count = 1;
            numWords++;
        }

        // Getting the next word from the string
        token = strtok(NULL, " ");
    }

    return numWords;
}

// Function to print the word counts in descending order of count
void printWordCounts(const WordCount *wordCounts, int numWords) {
    // Sorting the wordCounts array in descending order of count
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    // Printing the word counts
    for (int i = numWords - 1; i >= 0; i--) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    // Getting the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Creating an array to store the word counts
    WordCount wordCounts[100]; // Assuming a maximum of 100 unique words

    // Counting the occurrences of each word in the string
    int numWords = countWords(str, wordCounts);

    // Printing the word counts in descending order of count
    printWordCounts(wordCounts, numWords);

    return 0;
}