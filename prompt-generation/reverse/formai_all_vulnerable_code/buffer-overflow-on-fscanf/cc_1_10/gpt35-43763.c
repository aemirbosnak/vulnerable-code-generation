//FormAI DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10000 // Maximum number of words in the dictionary.
#define MAX_LENGTH 50 // Maximum length of word in dictionary.

// Structure to store information of a particular word.
struct wordInfo {
    char word[MAX_LENGTH];
    int frequency;
};

// Function to check if two words are the same.
int isEqual(char s1[], char s2[]) {
    if (strcmp(s1, s2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a word is present in the dictionary.
int searchInDictionary(char word[], struct wordInfo dictionary[], int dictionarySize) {
    int i;
    for (i = 0; i < dictionarySize; i++) {
        if (isEqual(dictionary[i].word, word)) {
            dictionary[i].frequency++;
            return 1;
        }
    }
    return 0;
}

// Function to read words from the input file and check for spelling errors.
void checkSpelling(char inputFilename[], struct wordInfo dictionary[], int dictionarySize) {
    FILE *inputFile;
    char word[MAX_LENGTH];
    int i, errorCount = 0;

    // Open input file and start reading words.
    inputFile = fopen(inputFilename, "r");
    while (fscanf(inputFile, "%s", word) != EOF) {
        // Check if word is present in dictionary.
        if (!searchInDictionary(word, dictionary, dictionarySize)) {
            printf("Possible spelling error: %s\n", word);
            errorCount++;
        }
    }

    // Print summary of spelling check.
    printf("\nTotal spelling errors found: %d\n", errorCount);
    printf("Summary of words checked:\n");
    for (i = 0; i < dictionarySize; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].frequency);
    }

    // Close input file.
    fclose(inputFile);
}

int main() {
    struct wordInfo dictionary[MAX_WORDS]; // Array to store words in dictionary.
    char dictionaryFilename[] = "dictionary.txt"; // Name of dictionary file.
    char inputFilename[] = "input.txt"; // Name of input (to be checked) file.
    FILE *dictionaryFile;
    char word[MAX_LENGTH];
    int dictionarySize = 0, i;

    // Open dictionary file for reading.
    dictionaryFile = fopen(dictionaryFilename, "r");

    // Read and store words in dictionary.
    while (fscanf(dictionaryFile, "%s", word) != EOF) {
        strcpy(dictionary[dictionarySize].word, word);
        dictionary[dictionarySize].frequency = 0;
        dictionarySize++;
    }

    // Close dictionary file.
    fclose(dictionaryFile);

    // Check spelling errors in input file.
    checkSpelling(inputFilename, dictionary, dictionarySize);

    return 0;
}