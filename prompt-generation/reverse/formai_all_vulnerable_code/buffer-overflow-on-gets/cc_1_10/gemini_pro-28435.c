//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the input text
#define MAX_WORDS 1000

// Define the structure of a word count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to compare two word counts
int compareWordCounts(const void *a, const void *b) {
    WordCount *wordCount1 = (WordCount *)a;
    WordCount *wordCount2 = (WordCount *)b;

    return strcmp(wordCount1->word, wordCount2->word);
}

// Function to count the words in a given string
int countWords(char *input, WordCount *wordCounts) {
    // Initialize the word count array
    for (int i = 0; i < MAX_WORDS; i++) {
        wordCounts[i].count = 0;
    }

    // Tokenize the input string into words
    char *token = strtok(input, " ");

    // Iterate over the words in the input string
    while (token != NULL) {
        // Find the index of the word in the word count array
        int index = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, wordCounts[i].word) == 0) {
                index = i;
                break;
            }
        }

        // If the word is not in the word count array, add it
        if (index == -1) {
            strcpy(wordCounts[index].word, token);
            index = index + 1;
        }

        // Increment the count of the word
        wordCounts[index].count++;

        // Get the next word in the input string
        token = strtok(NULL, " ");
    }

    // Return the number of words in the input string
    return index;
}

// Function to print the word counts
void printWordCounts(WordCount *wordCounts, int numWords) {
    // Sort the word counts in alphabetical order
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    // Print the word counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Main function
int main() {
    // Get the input text from the user
    char input[1000];
    printf("Enter the input text: ");
    gets(input);

    // Count the words in the input text
    WordCount wordCounts[MAX_WORDS];
    int numWords = countWords(input, wordCounts);

    // Print the word counts
    printWordCounts(wordCounts, numWords);

    return 0;
}