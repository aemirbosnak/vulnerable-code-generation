//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
// A unique spell checking program that uses introspection to analyze and correct words
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

// Struct definition for dictionary words
typedef struct {
    char word[MAX_WORD_LENGTH];
} DictionaryWord;

// Global variables for dictionary and its size
DictionaryWord dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

// Function to add a new word to the dictionary
void addToDictionary(char *word) {
    // Check if the word is already in the dictionary
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return;
        }
    }
    
    // Add the word to the dictionary
    strncpy(dictionary[dictionarySize].word, word, MAX_WORD_LENGTH);
    dictionarySize++;
}

// Function to load the dictionary from a file
void loadDictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Could not open dictionary file\n");
        exit(1);
    }
    
    char word[MAX_WORD_LENGTH];
    
    // Read each word from the file and add it to the dictionary
    while (fscanf(file, "%s", word) != EOF) {
        addToDictionary(word);
    }
    
    fclose(file);
}

// Function to check if a word is in the dictionary
int isDictionaryWord(char *word) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    
    return 0;
}

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to spell check a word and suggest corrections
void spellCheckWord(char *word) {
    // Check if the word is in the dictionary
    if (isDictionaryWord(word)) {
        printf("%s is spelled correctly\n", word);
        return;
    }
    
    // If not, suggest corrections
    printf("%s is misspelled. Possible corrections:\n", word);
    
    // Generate possible corrections by replacing, inserting, or deleting letters
    for (int i = 0; i < strlen(word); i++) {
        // Replace a letter
        for (char c = 'a'; c <= 'z'; c++) {
            char original = word[i];
            word[i] = c;
            if (isDictionaryWord(word)) {
                printf("- %s\n", word);
            }
            word[i] = original;
        }
        
        // Insert a letter
        char original = word[i];
        for (char c = 'a'; c <= 'z'; c++) {
            char newWord[MAX_WORD_LENGTH];
            strncpy(newWord, word, MAX_WORD_LENGTH);
            memmove(newWord+i+1, newWord+i, strlen(newWord+i)+1);
            newWord[i] = c;
            if (isDictionaryWord(newWord)) {
                printf("- %s\n", newWord);
            }
        }
        word[i] = original;
        
        // Delete a letter
        char newWord[MAX_WORD_LENGTH];
        strncpy(newWord, word, MAX_WORD_LENGTH);
        memmove(newWord+i, newWord+i+1, strlen(newWord+i+1)+1);
        if (isDictionaryWord(newWord)) {
            printf("- %s\n", newWord);
        }
    }
}

int main(int argc, char *argv[]) {
    // Load the dictionary
    if (argc != 2) {
        printf("Error: Please specify a dictionary file\n");
        return 1;
    }
    
    loadDictionary(argv[1]);
    
    // Prompt the user to enter a word to spell check
    printf("Enter a word to spell check:\n");
    char word[MAX_WORD_LENGTH];
    scanf("%s", word);
    
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    
    // Remove any non-letter characters from the beginning or end of the word
    int start = 0;
    int end = strlen(word) - 1;
    while (!isLetter(word[start])) {
        start++;
    }
    while (!isLetter(word[end])) {
        end--;
    }
    char newWord[MAX_WORD_LENGTH];
    memmove(newWord, word+start, end-start+1);
    newWord[end-start+1] = '\0';
    
    // Spell check the new word
    spellCheckWord(newWord);
    
    return 0;
}