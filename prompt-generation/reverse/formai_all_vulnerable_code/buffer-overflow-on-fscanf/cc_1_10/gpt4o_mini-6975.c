//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two words, used for sorting
int compare(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;
    return strcmp(word1->word, word2->word);
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Main function to count word frequencies
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    WordFrequency wordArray[MAX_WORDS];
    int wordCount = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word); // Convert to lowercase
        
        // Check for word already in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordArray[i].word, word) == 0) {
                wordArray[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the array
        if (!found) {
            if (wordCount < MAX_WORDS) {
                strcpy(wordArray[wordCount].word, word);
                wordArray[wordCount].frequency = 1;
                wordCount++;
            } else {
                fprintf(stderr, "Warning: Maximum word limit reached, some words may not be counted.\n");
                break;
            }
        }
    }

    fclose(file); // Close the file

    // Sort the words by their alphabetical order
    qsort(wordArray, wordCount, sizeof(WordFrequency), compare);

    // Print the word frequencies
    printf("Word Frequency Count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordArray[i].word, wordArray[i].frequency);
    }

    return 0;
}