//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structures for sorting
int compare(const void *a, const void *b) {
    return ((WordFrequency *)b)->frequency - ((WordFrequency *)a)->frequency;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to process the text file and summarize the frequency of words
void summarizeText(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "File could not be opened. Please ease my heart and check the file path.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS] = {0};
    int wordCount = 0;

    // Read words from file
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        
        // Check if the word is already counted
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                found = 1;
                break;
            }
        }
        
        // If the word is new, add it to the list
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordFrequencies[wordCount].word, word);
            wordFrequencies[wordCount].frequency = 1;
            wordCount++;
        }
    }
    
    fclose(file);

    // Sort the words by frequency
    qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compare);

    // Display the summary
    printf("Oh, sweet essence of words, my love:\n");
    printf("Let me narrate the whispers of your heart:\n");
    for (int i = 0; i < wordCount && i < 10; i++) { // Show top 10 words
        printf("In your verses, the word '%s' graced with frequency of %d times.\n",
                wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
    
    printf("A symphony of words, a dance of love.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Oh my dear user, i beseech thee, provide the text file as an argument.\n");
        return 1;
    }

    // Summarize the text from the given file
    summarizeText(argv[1]);
    
    return 0;
}