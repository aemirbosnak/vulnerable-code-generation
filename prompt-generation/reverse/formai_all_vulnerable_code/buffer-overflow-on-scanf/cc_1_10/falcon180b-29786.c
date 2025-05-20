//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to check if a word is in the dictionary
int isInDictionary(char *word) {
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionaryFile)!= NULL) {
        if (strcmp(line, word) == 0) {
            fclose(dictionaryFile);
            return 1;
        }
    }

    fclose(dictionaryFile);
    return 0;
}

// Function to load words from file into an array
void loadWords(char **words, int *numWords, FILE *file) {
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        words[i] = strdup(line);
        numWords[0]++;
        i++;
    }
}

// Function to check spelling of words in array
void checkSpelling(char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        char *word = words[i];
        if (isInDictionary(word)) {
            printf("%s is spelled correctly.\n", word);
        } else {
            printf("%s is misspelled.\n", word);
        }
    }
}

int main() {
    char *filename;
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char *words[MAX_WORDS];
    int numWords = 0;

    loadWords(words, &numWords, file);

    fclose(file);

    checkSpelling(words, numWords);

    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }

    return 0;
}