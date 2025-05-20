//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

// Define the structure for a word
typedef struct {
    char word[50];
    char translation[100];
} Word;

// Function prototypes
void loadWords(Word words[]);
void saveWords(Word words[], int numWords);
int searchWords(Word words[], int numWords, char* word);

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;

    // Load the dictionary
    loadWords(words);
    numWords = 0;

    // Main loop
    char input[100];
    while (1) {
        printf("Enter a sentence: ");
        fgets(input, 100, stdin);

        // Tokenize the input sentence
        char* token = strtok(input, " ");
        while (token!= NULL) {
            // Search for the word in the dictionary
            int index = searchWords(words, numWords, token);
            if (index == -1) {
                printf("%s: (unknown)\n", token);
            } else {
                printf("%s: %s\n", token, words[index].translation);
            }
            token = strtok(NULL, " ");
        }
    }

    return 0;
}

// Load the dictionary from a file
void loadWords(Word words[]) {
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(fp, "%s %s\n", words[numWords].word, words[numWords].translation)!= EOF) {
        numWords++;
    }

    fclose(fp);
}

// Save the dictionary to a file
void saveWords(Word words[], int numWords) {
    FILE* fp = fopen("dictionary.txt", "w");
    if (fp == NULL) {
        printf("Error saving dictionary.\n");
        exit(1);
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(fp, "%s %s\n", words[i].word, words[i].translation);
    }

    fclose(fp);
}

// Search for a word in the dictionary
int searchWords(Word words[], int numWords, char* word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return i;
        }
    }
    return -1;
}