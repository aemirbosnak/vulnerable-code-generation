//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 100

// Define the number of words to check
#define NUM_WORDS_TO_CHECK 100

// Define the dictionary file name
#define DICTIONARY_FILE_NAME "dictionary.txt"

// Define the function to load the dictionary into memory
int loadDictionary(char *dictionary[], int *numWords) {
    // Open the dictionary file
    FILE *dictionaryFile = fopen(DICTIONARY_FILE_NAME, "r");
    if (dictionaryFile == NULL) {
        return -1;
    }

    // Read the number of words in the dictionary
    fscanf(dictionaryFile, "%d", numWords);

    // Allocate memory for the dictionary
    *dictionary = malloc(*numWords * sizeof(char *));
    if (*dictionary == NULL) {
        return -1;
    }

    // Read the words from the dictionary
    for (int i = 0; i < *numWords; i++) {
        fscanf(dictionaryFile, "%s", *dictionary + i);
    }

    // Close the dictionary file
    fclose(dictionaryFile);

    return 0;
}

// Define the function to check the spelling of a word
int checkSpelling(char *word, char *dictionary[], int numWords) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary
    return 0;
}

// Define the main function
int main() {
    // Declare the variables
    char *dictionary[NUM_WORDS_TO_CHECK];
    int numWords;
    char word[MAX_WORD_LENGTH];

    // Load the dictionary into memory
    if (loadDictionary(dictionary, &numWords) != 0) {
        printf("Error loading the dictionary.\n");
        return -1;
    }

    // Get the word to check
    printf("Enter the word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    if (checkSpelling(word, dictionary, numWords)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    // Free the memory allocated for the dictionary
    free(dictionary);

    return 0;
}