//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the word and its count
typedef struct {
    char* word;
    int count;
} WordCount;

// Function to compare two WordCount structs
int compareWordCounts(const void* a, const void* b) {
    WordCount* wc1 = (WordCount*)a;
    WordCount* wc2 = (WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to create a WordCount struct for a given word
WordCount* createWordCount(char* word) {
    WordCount* wc = malloc(sizeof(WordCount));
    wc->word = strdup(word);
    wc->count = 1;
    return wc;
}

// Function to add a word to a list of WordCount structs
void addWordToList(WordCount** list, int* size, char* word) {
    // Check if the word is already in the list
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i]->word, word) == 0) {
            list[i]->count++;
            return;
        }
    }

    // If the word is not in the list, add it
    list = realloc(list, (*size + 1) * sizeof(WordCount*));
    list[*size] = createWordCount(word);
    (*size)++;
}

// Function to print the list of WordCount structs
void printWordCounts(WordCount** list, int size) {
    qsort(list, size, sizeof(WordCount*), compareWordCounts);
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", list[i]->word, list[i]->count);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char* str = malloc(1000);
    printf("Enter a string: ");
    gets(str);

    // Count the number of words in the string
    int numWords = countWords(str);

    // Create an array of WordCount structs to store the word counts
    WordCount** list = malloc(numWords * sizeof(WordCount*));
    int size = 0;

    // Tokenize the string and add each word to the list
    char* token = strtok(str, " ");
    while (token != NULL) {
        addWordToList(list, &size, token);
        token = strtok(NULL, " ");
    }

    // Print the list of word counts
    printWordCounts(list, size);

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        free(list[i]->word);
        free(list[i]);
    }
    free(list);
    free(str);

    return 0;
}