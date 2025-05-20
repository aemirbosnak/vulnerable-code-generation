//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

// function to convert a string to lowercase
void toLowerCase(char *word) {
    int i;
    for(i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int main(void) {

    char dictionary[10000][MAX_WORD_LENGTH];
    int dictionarySize = 0;
    char inputWord[MAX_WORD_LENGTH];
    char lowercaseWord[MAX_WORD_LENGTH];
    int i, j, found;

    FILE *dictionaryFile = fopen(DICTIONARY_FILE, "r");
    if (dictionaryFile == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    // read words from dictionary file and store them in an array
    while (fscanf(dictionaryFile, "%s", dictionary[dictionarySize++]) != EOF);

    // remove trailing newline characters from dictionary words
    for (i = 0; i < dictionarySize; i++) {
        char *newlineChar = strchr(dictionary[i], '\n');
        if (newlineChar != NULL) {
            *newlineChar = '\0';
        }
    }

    fclose(dictionaryFile);

    // prompt user to enter word to spell check
    printf("Enter a word to spell check: ");
    scanf("%s", inputWord);

    // convert entered word to lowercase
    strcpy(lowercaseWord, inputWord);
    toLowerCase(lowercaseWord);

    // check if entered word is in dictionary
    found = 0;
    for (i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i], lowercaseWord) == 0) {
            found = 1;
            break;
        }
    }

    // print result of spell check
    if (found) {
        printf("%s is spelled correctly!\n", inputWord);
    } else {
        printf("%s is spelled incorrectly.\n", inputWord);
        printf("Did you mean: \n");

        // suggest similar words from dictionary
        for (i = 0; i < dictionarySize; i++) {
            int differentLetters = 0;
            if (strlen(dictionary[i]) == strlen(lowercaseWord)) {
                for (j = 0; j < strlen(dictionary[i]); j++) {
                    if (dictionary[i][j] != lowercaseWord[j]) {
                        differentLetters++;
                    }
                }
                if (differentLetters == 1) {
                    printf("%s\n", dictionary[i]);
                }
            }
        }
    }

    return 0;
}