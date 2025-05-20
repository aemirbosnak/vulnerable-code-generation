//FormAI DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICTIONARY_LEN 2000

// Function declarations
int readDictionary(char dictionary[][MAX_WORD_LEN+1], const char* fileName);
int checkWord(const char* word, char dictionary[][MAX_WORD_LEN+1], const int numWords);
void lowercase(char* word);

int main() {
    char dictionary[MAX_DICTIONARY_LEN][MAX_WORD_LEN+1];
    const char* dictionaryFileName = "dictionary.txt";

    // Read in the dictionary file
    int numWords = readDictionary(dictionary, dictionaryFileName);
    printf("Dictionary loaded with %d words\n", numWords);

    // Take input from user
    char input[MAX_WORD_LEN+1];
    printf("Enter a word: ");
    scanf("%s", input);

    // Lowercase the word for comparison to dictionary
    lowercase(input);

    // Check if the word is in the dictionary
    int result = checkWord(input, dictionary, numWords);

    if (result) {
        printf("The word '%s' is spelled correctly!\n", input);
    } else {
        printf("The word '%s' is misspelled\n", input);
    }

    return 0;
}

// Reads in the dictionary file and populates the array with words
int readDictionary(char dictionary[][MAX_WORD_LEN+1], const char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return 0;
    }
    char word[MAX_WORD_LEN+1];
    int i = 0;
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[i], word);
        i++;
    }
    fclose(fp);
    return i;
}

// Checks if a word is in the dictionary
int checkWord(const char* word, char dictionary[][MAX_WORD_LEN+1], const int numWords) {
    for (int i = 0; i < numWords; i++) {
        // Case insensitive comparison
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Converts a string to all lowercase characters
void lowercase(char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}