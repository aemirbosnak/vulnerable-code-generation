//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WORD_LENGTH 30
#define DICTIONARY_FILE "dictionary.txt"

// Function prototype
int isWordInDictionary(char[], FILE*);

// Main function
int main(void) {
    char word[WORD_LENGTH];
    FILE *dictFile;
    
    // Open dictionary file for reading
    dictFile = fopen(DICTIONARY_FILE, "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    
    // Prompt user to enter a word
    printf("Enter a word to check for spelling: ");
    scanf("%s", word);
    
    // Convert word to lowercase
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
    
    // Check if word is in dictionary
    if (isWordInDictionary(word, dictFile)) {
        printf("%s is spelled correctly!\n", word);
    }
    else {
        printf("%s is spelled incorrectly!\n", word);
    }
    
    // Close dictionary file
    fclose(dictFile);
    
    return 0;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(char word[], FILE *dictFile) {
    char dictWord[WORD_LENGTH];
    
    // Loop through each word in dictionary file
    while (fscanf(dictFile, "%s", dictWord) != EOF) {
        
        // If dictionary word matches user word, return true
        if (strcmp(dictWord, word) == 0) {
            return 1;
        }
    }
    
    // If word is not found, return false
    return 0;
}