//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int count;
};

// Function prototypes
void toLowerCase(char *str);
int findWord(struct WordFrequency *words, int numWords, const char *word);
void addWord(struct WordFrequency *words, int *numWords, const char *word);
void printWordFrequencies(struct WordFrequency *words, int numWords);
void cleanWord(char *word);

// Main function
int main() {
    FILE *file;
    char filename[100];
    char currentWord[MAX_WORD_LENGTH];
    struct WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the filename to analyze: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return 1;
    }

    while (fscanf(file, "%s", currentWord) != EOF) {
        cleanWord(currentWord);
        if (strlen(currentWord) > 0) {
            toLowerCase(currentWord);
            addWord(words, &numWords, currentWord);
        }
    }

    fclose(file);
    printWordFrequencies(words, numWords);

    return 0;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to clean up the word by removing punctuation
void cleanWord(char *word) {
    char *cleanedWord = word;
    int len = strlen(word);

    // Remove punctuation from start
    while (len > 0 && !isalnum((unsigned char)word[0])) {
        cleanedWord++;
        len--;
    }

    // Remove punctuation from end
    while (len > 0 && !isalnum((unsigned char)word[len - 1])) {
        word[len - 1] = '\0';
        len--;
    }

    // If word gets empty, set empty string
    if (len <= 0) {
        cleanedWord[0] = '\0';
    } else {
        strcpy(word, cleanedWord);
    }
}

// Function to find if the word already exists in the array
int findWord(struct WordFrequency *words, int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // return the index
        }
    }
    return -1; // not found
}

// Function to add word to the frequency list
void addWord(struct WordFrequency *words, int *numWords, const char *word) {
    int index = findWord(words, *numWords, word);

    if (index != -1) {
        // Word already exists, increment count
        words[index].count++;
    } else {
        // Add new word
        strcpy(words[*numWords].word, word);
        words[*numWords].count = 1;
        (*numWords)++;
    }
}

// Function to print word frequencies
void printWordFrequencies(struct WordFrequency *words, int numWords) {
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("'%s': %d\n", words[i].word, words[i].count);
    }
}