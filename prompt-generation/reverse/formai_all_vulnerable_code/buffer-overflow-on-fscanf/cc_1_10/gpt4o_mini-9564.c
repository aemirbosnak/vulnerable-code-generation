//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int main() {
    FILE *file;
    char *filename = "input.txt";
    char word[MAX_WORD_LEN];
    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;

    // Open the file 
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return 1;
    }

    // Read words from the file and count their frequencies
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        
        // Check if word is already in the list
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, word) == 0) {
                wordList[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found && wordCount < MAX_WORDS) {
            strncpy(wordList[wordCount].word, word, MAX_WORD_LEN);
            wordList[wordCount].count = 1;
            wordCount++;
        }
    }
    
    // Close the file
    fclose(file);

    // Sorting the word frequencies using Bubble sort for educational purposes
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (wordList[j].count < wordList[j + 1].count) {
                WordFrequency temp = wordList[j];
                wordList[j] = wordList[j + 1];
                wordList[j + 1] = temp;
            }
        }
    }

    // Display the results
    printf("Word Frequency List:\n");
    printf("=====================\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}