//FormAI DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>

#define WORD_LEN 50
#define DICT_SIZE 100

// Bravely declaring global variables
char dictionary[DICT_SIZE][WORD_LEN];
int dict_size = 0;

// Function to read dictionary file and save words into global dictionary array
void readDictionaryFile(char* filename) {
    FILE* fp;
    char word[WORD_LEN];
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.");
        exit(1);
    }
    
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[dict_size], word);
        dict_size++;
    }
    
    fclose(fp);
}

// Function to check if a word is in the dictionary
int isWordInDictionary(char* word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    
    return 0;
}

// Function to print a suggestion for a misspelled word
void printSuggestion(char* word) {
    char suggestion[WORD_LEN];
    int suggestion_found = 0;
    
    // Check for suggestions with one character difference
    for (int i = 0; i < dict_size; i++) {
        int diff_count = 0;
        for (int j = 0; j < strlen(word); j++) {
            if (word[j] != dictionary[i][j]) {
                diff_count++;
            }
        }
        
        if (diff_count == 1) {
            strcpy(suggestion, dictionary[i]);
            suggestion_found = 1;
            break;
        }
    }
    
    if (suggestion_found) {
        printf("Did you mean %s?\n", suggestion);
    } else {
        printf("Word not found in dictionary and no suggestions available.\n");
    }
}

int main() {
    // Read dictionary file
    readDictionaryFile("dictionary.txt");
    
    // Get user input and check if word is in dictionary
    char input[WORD_LEN];
    printf("Enter a word: ");
    scanf("%s", input);
    
    if (isWordInDictionary(input)) {
        printf("Word found in dictionary.\n");
    } else {
        printf("Word not found in dictionary.\n");
        printSuggestion(input);
    }
    
    return 0;
}