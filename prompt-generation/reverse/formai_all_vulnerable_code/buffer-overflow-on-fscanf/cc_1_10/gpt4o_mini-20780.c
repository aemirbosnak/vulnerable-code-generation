//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Struct to hold words and their frequencies
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to find a word in the array of WordCount structures
int findWord(WordCount words[], int totalWords, const char* word) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print the summary of word counts
void printSummary(WordCount words[], int totalWords) {
    printf("\n🎉 Word Frequency Summary 🎉\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < totalWords; i++) {
        printf("Word: '%s' | Count: %d\n", words[i].word, words[i].count);
    }
    printf("----------------------------------------\n");
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("🌼 Welcome to the Happy Text Summarizer! 🌼\n");
    printf("Please enter the filename to summarize: ");
    
    // Get input filename
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oh no! I couldn't open the file. Please make sure it exists and try again. 😊\n");
        return 1;
    }

    WordCount words[MAX_WORDS] = {0};
    int totalWords = 0;
    char word[MAX_WORD_LENGTH];

    // Read words from the file and count their occurrences
    while (fscanf(file, "%s", word) != EOF) {
        // Normalize the word: convert to lower case
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the array
        int index = findWord(words, totalWords, word);
        if (index != -1) {
            words[index].count++;
        } else {
            // Add new word to the array
            strcpy(words[totalWords].word, word);
            words[totalWords].count = 1;
            totalWords++;
        }
    }

    fclose(file);

    // Print the summary of words
    printSummary(words, totalWords);
    
    printf("🎊 Thank you for using the Happy Text Summarizer! 🎊\n");
    return 0;
}