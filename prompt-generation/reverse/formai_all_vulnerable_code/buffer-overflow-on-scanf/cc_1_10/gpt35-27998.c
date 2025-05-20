//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
/**
 * C Word Frequency Counter program 
 * Written in Linus Torvalds style
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum length of a word in the input text
#define MAX_FILE_NAME_LEN 50 // Maximum length of a file name
#define MAX_WORDS 1000 // Maximum number of unique words in the input text
#define MAX_FREQ 1000 // Maximum frequency of a word in the input text

/**
 * Structure for storing a word and its frequency
**/
struct wordFreq {
    char word[MAX_WORD_LEN]; // The word
    int freq; // The frequency of the word
};

/**
 * Function to compare two words based on their frequencies
**/
int compareWordFreq(const void *a, const void *b) {
    const struct wordFreq *word1 = (const struct wordFreq *)a;
    const struct wordFreq *word2 = (const struct wordFreq *)b;
    return (word2->freq - word1->freq);
}

/**
 * Function to check if a character is a delimiter
**/
int isDelimiter(char c) {
    return (c == ' ' || c == ',' || c == '.' || c == '\n' || c == '\r');
}

/**
 * Main function
**/
int main() {
    // Define variables
    char fileName[MAX_FILE_NAME_LEN];
    char word[MAX_WORD_LEN];
    FILE *file;
    int wordCount = 0;
    struct wordFreq wordFreqArr[MAX_WORDS] = {{"", 0}};
    char c;
    int i, j;

    // Get the file name
    printf("Enter the name of the file:");
    scanf("%s", fileName);

    // Open the file
    file = fopen(fileName, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", fileName);
        exit(1);
    }

    // Read the contents of the file
    while ((c = fgetc(file)) != EOF) {
        // If a delimiter is encountered, the current word is complete
        if (isDelimiter(c)) {
            // If the word is not empty, store its frequency
            if (strlen(word) > 0) {
                // Check if the word already exists in the array
                for (i = 0; i < wordCount; i++) {
                    if (strcmp(wordFreqArr[i].word, word) == 0) {
                        // The word already exists, increment its frequency
                        wordFreqArr[i].freq++;
                        break;
                    }
                }
                // If the word does not exist in the array, add it
                if (i == wordCount) {
                    strncpy(wordFreqArr[wordCount].word, word, MAX_WORD_LEN);
                    wordFreqArr[wordCount].freq = 1;
                    wordCount++;
                }
                // Reset the word
                memset(word, 0, MAX_WORD_LEN);
            }
        }
        else {
            // Append the character to the current word
            if (strlen(word) < MAX_WORD_LEN) {
                word[strlen(word)] = c;
            }
        }
    }
    // If the file does not end with a delimiter, the last word is not yet processed
    if (strlen(word) > 0) {
        // Check if the word already exists in the array
        for (i = 0; i < wordCount; i++) {
            if (strcmp(wordFreqArr[i].word, word) == 0) {
                // The word already exists, increment its frequency
                wordFreqArr[i].freq++;
                break;
            }
        }
        // If the word does not exist in the array, add it
        if (i == wordCount) {
            strncpy(wordFreqArr[wordCount].word, word, MAX_WORD_LEN);
            wordFreqArr[wordCount].freq = 1;
            wordCount++;
        }
    }

    // Sort the array of word frequencies
    qsort(wordFreqArr, wordCount, sizeof(struct wordFreq), compareWordFreq);

    // Print the top 10 words by frequency
    printf("The top 10 words by frequency are:\n");
    for (i = 0; i < 10 && i < wordCount; i++) {
        printf("%d. %s - %d\n", i+1, wordFreqArr[i].word, wordFreqArr[i].freq);
    }

    // Close the file
    fclose(file);

    // Return success
    return 0;
}