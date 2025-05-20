//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define BUFFER_SIZE 1024

typedef struct {
    char words[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int count;
} Dictionary;

// Function to load the dictionary from a file
int loadDictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        return -1;
    }
    
    dict->count = 0;
    while (fscanf(file, "%s", dict->words[dict->count]) == 1) {
        dict->count++;
        if (dict->count >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary size exceeded!\n");
            break;
        }
    }
    
    fclose(file);
    return 0;
}

// Function to convert a word to lowercase
void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is in the dictionary
int checkWord(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to spell check a given text
void spellCheck(Dictionary *dict, const char *text) {
    char word[MAX_WORD_LENGTH];
    int index = 0;
    int inWord = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            word[index++] = text[i];
            inWord = 1;
        } else {
            if (inWord) {
                word[index] = '\0';
                toLowerCase(word);
                if (!checkWord(dict, word)) {
                    printf("Misspelled: %s\n", word);
                }
                index = 0;
            }
            inWord = 0;
        }
    }
    
    if (inWord) { // Handle last word if it ends without punctuation
        word[index] = '\0';
        toLowerCase(word);
        if (!checkWord(dict, word)) {
            printf("Misspelled: %s\n", word);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }
    
    Dictionary dict;
    if (loadDictionary(&dict, argv[1]) != 0) {
        return 1; // Error loading dictionary
    }
    
    FILE *textFile = fopen(argv[2], "r");
    if (!textFile) {
        fprintf(stderr, "Could not open text file: %s\n", argv[2]);
        return 1;
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, textFile)) {
        spellCheck(&dict, buffer);
    }
    
    fclose(textFile);
    return 0;
}