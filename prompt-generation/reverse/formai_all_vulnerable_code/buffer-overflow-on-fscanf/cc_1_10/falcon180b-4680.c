//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 100000

// Function to load dictionary into memory
void loadDictionary(char *dictionaryFile, char **dictionary) {
    FILE *file = fopen(dictionaryFile, "r");
    if (!file) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s", dictionary[wordCount])!= EOF) {
        wordCount++;
    }
    fclose(file);
}

// Function to check if a word is in the dictionary
bool isInDictionary(char *word, char **dictionary) {
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength; i++) {
        if (!isalpha(word[i])) {
            word[i] = tolower(word[i]);
        }
    }

    for (int i = 0; i < MAX_DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }

    return false;
}

// Function to check spelling of a sentence
void checkSpelling(char *sentence, char **dictionary) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    strcpy(word, "");
    for (int i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            if (strlen(word) > 0) {
                if (!isInDictionary(word, dictionary)) {
                    printf("Possible spelling error: %s\n", word);
                }
            }
            word[0] = '\0';
        } else {
            strncat(word, &sentence[i], 1);
        }
    }

    if (strlen(word) > 0 &&!isInDictionary(word, dictionary)) {
        printf("Possible spelling error: %s\n", word);
    }
}

int main() {
    char dictionaryFile[100] = "dictionary.txt";
    char sentence[1000] = "This is a sample sentence for spell checking. It contains some common misspellings like recieve and seperate. ";

    char *dictionary[MAX_DICTIONARY_SIZE];
    loadDictionary(dictionaryFile, dictionary);

    checkSpelling(sentence, dictionary);

    return 0;
}