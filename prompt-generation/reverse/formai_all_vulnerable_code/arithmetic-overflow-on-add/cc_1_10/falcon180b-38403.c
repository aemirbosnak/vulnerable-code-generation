//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000 // Maximum number of words in dictionary
#define MAX_WORD_LENGTH 100 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH]; // Word
    bool isCorrect; // Flag indicating if word is correct or not
} Word;

typedef struct {
    Word words[MAX_WORDS]; // Array of words
    int numWords; // Number of words in dictionary
} Dictionary;

void loadDictionary(Dictionary* dict, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strlen(line) > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", line);
            exit(1);
        }

        Word word = {.word = line,.isCorrect = true };
        dict->words[dict->numWords] = word;
        dict->numWords++;
    }

    fclose(fp);
}

void checkSpelling(Dictionary* dict, char* text) {
    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            int j = 1;
            while (isalnum(text[i+j]) && j < MAX_WORD_LENGTH) {
                word[j] = tolower(text[i+j]);
                j++;
            }
            word[j] = '\0';

            bool found = false;
            for (int k = 0; k < dict->numWords; k++) {
                if (strcmp(dict->words[k].word, word) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("Misspelled word: %s\n", word);
            }
        } else {
            printf("Unknown character: %c\n", text[i]);
        }
        i++;
    }
}

int main() {
    Dictionary dict;
    loadDictionary(&dict, "dictionary.txt");

    char text[1000000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    checkSpelling(&dict, text);

    return 0;
}