//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to convert input to lowercase for uniformity
void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to check if a word exists in the frequency list
int findWord(WordFrequency *wordFreqList, int currentSize, const char *word) {
    for (int i = 0; i < currentSize; i++) {
        if (strcmp(wordFreqList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display words and their frequencies
void displayFrequencies(WordFrequency *wordFreqList, int size) {
    printf("\nWord Frequency Count:\n");
    printf("======================\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordFreqList[i].word, wordFreqList[i].count);
    }
}

int main() {
    char inputText[10000];
    WordFrequency wordFreqList[MAX_WORDS];
    int totalWords = 0;

    printf("Hello there! 🎉\n");
    printf("Let's count some words! Please enter your text below:\n");
    
    // Get user input
    printf("Enter text (end with a single dot '.'): ");
    fgets(inputText, sizeof(inputText), stdin);

    // Ensure the input ends with a dot
    if (inputText[strlen(inputText) - 2] == '.') {
        inputText[strlen(inputText) - 2] = '\0';
    } else {
        printf("Oops! Make sure to end with a dot (.) next time!\n");
        return 1;
    }

    // Tokenizing the input text
    char *token = strtok(inputText, " \n");
    while (token != NULL) {
        // Remove punctuation from the word
        for (int i = 0; token[i]; i++) {
            if (ispunct((unsigned char)token[i])) {
                token[i] = '\0'; // Replace punctuation with a null character
                break;
            }
        }

        toLower(token); // Convert to lowercase
        
        // Check if the word is in the list
        int index = findWord(wordFreqList, totalWords, token);
        if (index != -1) {
            wordFreqList[index].count++; // Increment count if found
        } else {
            // Add new word to the list
            strcpy(wordFreqList[totalWords].word, token);
            wordFreqList[totalWords].count = 1;
            totalWords++;
        }
        token = strtok(NULL, " \n");
    }

    // Display results
    displayFrequencies(wordFreqList, totalWords);

    printf("Yay! We did it! 🎊 Thank you for using the Word Frequency Counter!\n");
    return 0;
}