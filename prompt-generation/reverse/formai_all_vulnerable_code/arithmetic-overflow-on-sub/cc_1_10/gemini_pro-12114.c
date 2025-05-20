//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the array
#define MAX_WORDS 100

// Define the maximum length of each word
#define MAX_WORD_LENGTH 20

// Define a structure to represent a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

// Create an array of words
Word words[MAX_WORDS];

// Get the number of words from the user
int getNumberOfWords() {
    int numberOfWords;
    printf("Enter the number of words: ");
    scanf("%d", &numberOfWords);
    return numberOfWords;
}

// Get the words from the user
void getWords(int numberOfWords) {
    for (int i = 0; i < numberOfWords; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }
}

// Sort the words in ascending order
void sortWords(int numberOfWords) {
    for (int i = 0; i < numberOfWords - 1; i++) {
        for (int j = i + 1; j < numberOfWords; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Print the sorted words
void printWords(int numberOfWords) {
    for (int i = 0; i < numberOfWords; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

// Main function
int main() {
    int numberOfWords = getNumberOfWords();
    getWords(numberOfWords);
    sortWords(numberOfWords);
    printWords(numberOfWords);
    return 0;
}