//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// A structure to hold the words and their frequencies
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to normalize the word (to lowercase)
void normalize(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word exists in the array
int findWord(WordFrequency *words, int wordCount, const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function to read the file and count word frequencies
int main() {
    FILE *file;
    char filename[100];
    WordFrequency words[MAX_WORDS];
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];

    printf("Welcome to the Word Frequency Counter!\n");
    printf("Please enter the filename to analyze: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return EXIT_FAILURE;
    }

    // Read words from the file and count their frequencies
    while (fscanf(file, "%s", word) != EOF) {
        // Normalize the word
        normalize(word);
        
        // Check if the word is already counted
        int index = findWord(words, wordCount, word);
        if (index != -1) {
            words[index].count++; // Increment count if found
        } else {
            // If it's a new word, add to the array
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }

        // Ensure we don’t exceed MAX_WORDS
        if (wordCount >= MAX_WORDS) {
            printf("Maximum word limit reached. Some words may not be counted!\n");
            break;
        }
    }

    // Close the file
    fclose(file);

    // Display the word frequencies
    printf("\nWord Count Results:\n");
    printf("---------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("Word: %s - Frequency: %d\n", words[i].word, words[i].count);
    }

    printf("---------------------\n");
    printf("Total unique words: %d\n", wordCount);
    printf("Thank you for using the Word Frequency Counter! 🎉\n");

    return EXIT_SUCCESS;
}