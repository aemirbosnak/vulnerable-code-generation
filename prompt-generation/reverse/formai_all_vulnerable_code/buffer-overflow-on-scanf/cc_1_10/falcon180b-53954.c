//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to check if a word is in the dictionary
int isInDictionary(char* word) {
    FILE* dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file\n");
        return 0;
    }

    char dictWord[MAX_WORD_LENGTH];
    while (fscanf(dictFile, "%s", dictWord)!= EOF) {
        if (strcmp(word, dictWord) == 0) {
            fclose(dictFile);
            return 1;
        }
    }

    fclose(dictFile);
    return 0;
}

// Function to read a file and check spelling
void spellCheck(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    // Read file and check spelling of each word
    while (fscanf(file, "%s", word)!= EOF) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is in dictionary
        if (!isInDictionary(word)) {
            printf("Possible spelling error: %s\n", word);
            wordCount++;
        }
    }

    fclose(file);
    printf("Found %d possible spelling errors\n", wordCount);
}

int main() {
    char filename[100];
    printf("Enter filename to check spelling: ");
    scanf("%s", filename);
    spellCheck(filename);
    return 0;
}