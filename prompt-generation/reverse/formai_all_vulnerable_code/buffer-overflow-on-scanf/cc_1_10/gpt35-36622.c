//FormAI DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Functions to handle decentralized spell checking
int checkWord(const char *word, const char **dictionary, int length);
void addWord(const char *word, const char ***dictionary, int *length);
void freeDictionary(const char **dictionary, int length);

int main() {
    const char *myDictionary[] = {"hello", "world", "spell", "checking"};
    int dictLength = 4;

    // Example usage
    char userInput[50];
    printf("Enter a word to check: ");
    scanf("%s", userInput);
    int result = checkWord(userInput, myDictionary, dictLength);
    if (result) {
        printf("'%s' is spelled correctly!\n", userInput);
    } else {
        printf("'%s' is spelled incorrectly.\n", userInput);
        addWord(userInput, &myDictionary, &dictLength);
        printf("'%s' added to dictionary.\n", userInput);
    }

    // Free memory used by dictionary
    freeDictionary(myDictionary, dictLength);
    return 0;
}

// Function to check if a word is in the dictionary
int checkWord(const char *word, const char **dictionary, int length) {
    for (int i = 0; i < length; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a word to the dictionary, with dynamic memory allocation
void addWord(const char *word, const char ***dictionary, int *length) {
    // Allocate memory for new dictionary
    const char **newDict = malloc((*length + 1) * sizeof(char *));
    if (newDict == NULL) {
        printf("Error adding word: out of memory\n");
        return;
    }
    // Copy old dictionary into new dictionary
    memcpy(newDict, *dictionary, *length * sizeof(char *));
    // Add new word to new dictionary
    newDict[*length] = word;
    // Update dictionary and length pointers
    *dictionary = newDict;
    (*length)++;
}

// Function to initalize the dictionary
const char **initDictionary(int *length) {
    const char *dictionary[] = {"hello", "world", "spell", "checking"};
    *length = 4;
    return dictionary;
}

// Function to free memory used by dictionary
void freeDictionary(const char **dictionary, int length) {
    for (int i = 0; i < length; i++) {
        free((char *) dictionary[i]);
    }
    free(dictionary);
}