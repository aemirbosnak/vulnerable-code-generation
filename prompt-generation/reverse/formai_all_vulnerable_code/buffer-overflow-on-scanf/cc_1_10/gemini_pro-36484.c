//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure to represent a word and its count
typedef struct WordCount {
    char* word;
    int count;
} WordCount;

// Function to compare two WordCount structs by their word
int compareWordCount(const void* a, const void* b) {
    const WordCount* wordCount1 = (const WordCount*)a;
    const WordCount* wordCount2 = (const WordCount*)b;
    return strcmp(wordCount1->word, wordCount2->word);
}

// Function to print a WordCount struct
void printWordCount(WordCount* wordCount) {
    printf("%s: %d\n", wordCount->word, wordCount->count);
}

// Function to read a text file and count the occurrences of each word
void countWords(const char* filename) {
    // Open the text file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Create an array of WordCount structs to store the word counts
    WordCount* wordCounts = malloc(sizeof(WordCount) * 100);
    int numWordCounts = 0;

    // Read the file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into words
        char* words[100];
        int numWords = 0;
        char* word = strtok(line, " ");
        while (word != NULL) {
            words[numWords++] = word;
            word = strtok(NULL, " ");
        }

        // Count the occurrences of each word
        for (int i = 0; i < numWords; i++) {
            // Check if the word is already in the array
            int found = 0;
            for (int j = 0; j < numWordCounts; j++) {
                if (strcmp(words[i], wordCounts[j].word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }

            // If the word is not in the array, add it
            if (!found) {
                wordCounts[numWordCounts].word = strdup(words[i]);
                wordCounts[numWordCounts].count = 1;
                numWordCounts++;
            }
        }
    }

    // Close the text file
    fclose(file);

    // Sort the array of WordCount structs by the word
    qsort(wordCounts, numWordCounts, sizeof(WordCount), compareWordCount);

    // Print the word counts
    for (int i = 0; i < numWordCounts; i++) {
        printWordCount(&wordCounts[i]);
    }

    // Free the memory allocated for the WordCount structs
    for (int i = 0; i < numWordCounts; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);
}

int main() {
    // Get the name of the text file from the user
    char filename[256];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    // Count the words in the text file
    countWords(filename);

    return 0;
}