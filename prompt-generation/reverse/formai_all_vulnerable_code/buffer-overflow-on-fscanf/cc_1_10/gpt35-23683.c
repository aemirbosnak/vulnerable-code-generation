//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

/* Struct to store the word and its frequency */
struct WordFreq {
    char word[MAX_WORD_LENGTH];
    int freq;
};
typedef struct WordFreq WordFreq;

/* Function to check if a given character is a letter */
int isLetter(char c) {
    return isalpha(c) || c == '\'';
}

/* Function to read in words from a file and count their frequency */
int readWords(FILE* fp, WordFreq* wordFreqs) {
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    while (fscanf(fp, "%s", word) != EOF) {
        // Remove punctuation from end of word
        int len = strlen(word);
        while (len > 0 && !isLetter(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }
        // Remove punctuation from beginning of word
        int start = 0;
        while (start < len && !isLetter(word[start])) {
            start++;
        }
        // Add word to frequency array
        if (start < len) {
            // Convert word to lowercase
            for (int i = start; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            // Check if word already exists in frequency array
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, wordFreqs[i].word) == 0) {
                    wordFreqs[i].freq++;
                    found = 1;
                    break;
                }
            }
            // Add new word to frequency array
            if (!found) {
                strcpy(wordFreqs[numWords].word, word);
                wordFreqs[numWords].freq = 1;
                numWords++;
            }
        }
        // Check if maximum number of words has been reached
        if (numWords == MAX_NUM_WORDS) {
            break;
        }
    }
    return numWords;
}

/* Function to sort the frequency array by frequency in descending order */
void sortFreqs(WordFreq* wordFreqs, int numWords) {
    // Bubble sort the frequency array in descending order
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (wordFreqs[j].freq < wordFreqs[j + 1].freq) {
                WordFreq temp = wordFreqs[j];
                wordFreqs[j] = wordFreqs[j + 1];
                wordFreqs[j + 1] = temp;
            }
        }
    }
}

/* Function to print the frequency array */
void printFreqs(WordFreq* wordFreqs, int numWords) {
    printf("Word Frequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%-15s %d\n", wordFreqs[i].word, wordFreqs[i].freq);
    }
}

/* Main function */
int main(int argc, char** argv) {
    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    // Open file for reading
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }
    // Read words from file and count their frequency
    WordFreq wordFreqs[MAX_NUM_WORDS];
    int numWords = readWords(fp, wordFreqs);
    // Sort the frequency array by frequency in descending order
    sortFreqs(wordFreqs, numWords);
    // Print the frequency array
    printFreqs(wordFreqs, numWords);
    // Close file
    fclose(fp);
    // Exit program
    return 0;
}