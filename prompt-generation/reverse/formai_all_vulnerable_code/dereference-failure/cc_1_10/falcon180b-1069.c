//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100

// Function to compare two strings (case insensitive)
int compareStrings(char* str1, char* str2) {
    int i = 0;
    while (tolower(str1[i]) == tolower(str2[i])) {
        i++;
    }
    return i;
}

// Function to load dictionary into memory
void loadDictionary(char** dictionary, int* dictionarySize, FILE* fp) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (*dictionarySize >= MAX_DICTIONARY_SIZE) {
            printf("Dictionary is full. Cannot add more words.\n");
            return;
        }
        (*dictionary)[*dictionarySize] = strdup(word);
        (*dictionarySize)++;
    }
}

// Function to check if a word is in the dictionary
bool isInDictionary(char** dictionary, int dictionarySize, char* word) {
    for (int i = 0; i < dictionarySize; i++) {
        if (compareStrings(word, dictionary[i]) == strlen(word)) {
            return true;
        }
    }
    return false;
}

// Function to spell check a sentence
void spellCheck(char* sentence, char** dictionary, int dictionarySize) {
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!isInDictionary(dictionary, dictionarySize, word)) {
            printf("%s is not in the dictionary.\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char* dictionaryFile = "dictionary.txt";
    FILE* fp = fopen(dictionaryFile, "r");
    if (fp == NULL) {
        printf("Cannot open dictionary file.\n");
        return 1;
    }

    char** dictionary = malloc(MAX_DICTIONARY_SIZE * sizeof(char*));
    int dictionarySize = 0;
    loadDictionary(dictionary, &dictionarySize, fp);
    fclose(fp);

    char* sentence = "The quick brown fox jumps over the lazy dog.";
    printf("Spell checking sentence: %s\n", sentence);
    spellCheck(sentence, dictionary, dictionarySize);

    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}