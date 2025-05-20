//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICTIONARY_WORDS 1000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} DictionaryWord;

int loadDictionary(DictionaryWord dictionary[], int maxWords, FILE *dictFile) {
    int numWords = 0;

    while (fscanf(dictFile, "%s", dictionary[numWords].word)!= EOF) {
        numWords++;
        if (numWords == maxWords) {
            break;
        }
    }

    for (int i = 0; i < numWords; i++) {
        dictionary[i].frequency = 0;
    }

    return numWords;
}

int findWord(DictionaryWord dictionary[], int numWords, char *word) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

int suggestWords(DictionaryWord dictionary[], int numWords, char *word, char suggestions[][MAX_WORD_LEN]) {
    int i, j = 0;
    int maxEditDistance = strlen(word) / 2;

    for (i = 0; i < numWords; i++) {
        int editDistance = 0;
        int k;

        for (k = 0; k < strlen(dictionary[i].word); k++) {
            if (tolower(word[k])!= tolower(dictionary[i].word[k])) {
                editDistance++;
            }
        }

        if (editDistance <= maxEditDistance) {
            strcpy(suggestions[j], dictionary[i].word);
            j++;
        }
    }

    return j;
}

int main() {
    FILE *dictFile;
    char line[MAX_WORD_LEN];
    int numWords;
    DictionaryWord dictionary[MAX_DICTIONARY_WORDS];
    char inputWord[MAX_WORD_LEN];
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LEN];
    int numSuggestions;

    dictFile = fopen("dictionary.txt", "r");

    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    numWords = loadDictionary(dictionary, MAX_DICTIONARY_WORDS, dictFile);

    printf("Enter a word to check spelling:\n");
    fgets(inputWord, MAX_WORD_LEN, stdin);

    int wordIndex = findWord(dictionary, numWords, inputWord);

    if (wordIndex == -1) {
        printf("Word not found in dictionary.\n");
    } else {
        printf("Word found in dictionary.\n");
    }

    numSuggestions = suggestWords(dictionary, numWords, inputWord, suggestions);

    if (numSuggestions > 0) {
        printf("Did you mean:\n");

        for (int i = 0; i < numSuggestions; i++) {
            printf("%s\n", suggestions[i]);
        }
    }

    return 0;
}