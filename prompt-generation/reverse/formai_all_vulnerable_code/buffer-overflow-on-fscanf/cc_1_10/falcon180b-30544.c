//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Structure to store a word and its translation
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} WordTranslation;

// Function prototypes
void loadWords(WordTranslation words[]);
int searchWord(WordTranslation words[], int numWords, char *word);
void translateSentence(char sentence[], WordTranslation words[], int numWords);

int main() {
    WordTranslation words[MAX_WORDS];
    int numWords = 0;

    // Load the dictionary of words and their translations
    loadWords(words);
    numWords = sizeof(words) / sizeof(WordTranslation);

    // Get a sentence from the user
    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    // Translate the sentence
    translateSentence(sentence, words, numWords);

    return 0;
}

// Loads the dictionary of words and their translations from a file
void loadWords(WordTranslation words[]) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s\n", words[i].english, words[i].alien) == 2) {
        i++;
        if (i >= MAX_WORDS) {
            printf("Error: dictionary file is too large.\n");
            exit(1);
        }
    }

    fclose(file);
}

// Searches for a word in the dictionary and returns its index if found
int searchWord(WordTranslation words[], int numWords, char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].english) == 0) {
            return i;
        }
    }

    return -1;
}

// Translates a sentence by replacing each word with its alien translation
void translateSentence(char sentence[], WordTranslation words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    char *token;

    // Tokenize the sentence into words
    token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        // Search for the word in the dictionary
        int index = searchWord(words, numWords, token);
        if (index!= -1) {
            // Replace the word with its translation
            strcpy(word, words[index].alien);
        } else {
            // If the word is not found, leave it unchanged
            strcpy(word, token);
        }

        // Print the translated word followed by a space
        printf("%s ", word);

        // Get the next word
        token = strtok(NULL, ",.!?;:");
    }
}