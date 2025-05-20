//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to compare two words (for qsort)
int compare(const void* a, const void* b) {
    WordFrequency* wf1 = (WordFrequency*)a;
    WordFrequency* wf2 = (WordFrequency*)b;
    return strcmp(wf1->word, wf2->word);
}

// Function to check if a word exists in our word frequency list
int findWord(WordFrequency* words, int size, const char* word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // Return the index of the word
        }
    }
    return -1; // Not found
}

// Function to clean and normalize the input word
void cleanWord(char* word) {
    int len = strlen(word);
    int start = 0, end = len - 1;

    // Trim leading punctuation
    while (start < len && !isalnum(word[start])) {
        start++;
    }

    // Trim trailing punctuation
    while (end >= 0 && !isalnum(word[end])) {
        end--;
    }

    if (start <= end) {
        // Copy the cleaned word
        int newLength = end - start + 1;
        for (int i = 0; i < newLength; i++) {
            word[i] = tolower(word[start + i]); // Ensure lowercase
        }
        word[newLength] = '\0'; // Null-terminate the string
    } else {
        word[0] = '\0'; // Empty string
    }
}

// Function to read file and count word frequencies
int countWords(const char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1;
    }

    char buffer[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        cleanWord(buffer); // Clean the word

        if (buffer[0] != '\0') { // If there's a valid word
            int index = findWord(words, wordCount, buffer);
            if (index == -1) {
                // New word, add it to the list
                strcpy(words[wordCount].word, buffer);
                words[wordCount].count = 1;
                wordCount++;
            } else {
                // Word already exists, increment the count
                words[index].count++;
            }
        }
    }

    fclose(file);
    return wordCount; // Return the number of unique words
}

// Function to display the word frequencies
void displayFrequencies(WordFrequency* words, int size) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordFrequency words[MAX_WORDS];
    int wordCount = countWords(argv[1], words);
    
    if (wordCount < 0) {
        return EXIT_FAILURE; // Error while counting words
    }

    // Sort the words alphabetically
    qsort(words, wordCount, sizeof(WordFrequency), compare);

    // Display the sorted word frequencies
    displayFrequencies(words, wordCount);

    return EXIT_SUCCESS;
}