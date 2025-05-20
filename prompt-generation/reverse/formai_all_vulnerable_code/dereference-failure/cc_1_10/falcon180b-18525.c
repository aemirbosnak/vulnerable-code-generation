//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word *words;
    int size;
} Dictionary;

void initializeDictionary(Dictionary *dictionary) {
    dictionary->size = 0;
    dictionary->words = (Word *) malloc(MAX_DICTIONARY_SIZE * sizeof(Word));
}

void addWordToDictionary(Dictionary *dictionary, char *word) {
    Word newWord;
    strcpy(newWord.word, word);
    newWord.length = strlen(word);

    if (dictionary->size >= MAX_DICTIONARY_SIZE) {
        printf("Dictionary is full.\n");
        return;
    }

    dictionary->words[dictionary->size++] = newWord;
}

int isValidWord(Dictionary *dictionary, char *word) {
    int i;
    for (i = 0; i < dictionary->size; i++) {
        if (strcmp(dictionary->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void spellCheck(Dictionary *dictionary, char *text) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[j++] = tolower(text[i]);
        } else {
            if (j > 0) {
                if (!isValidWord(dictionary, word)) {
                    printf("Misspelled word: %s\n", word);
                }
                j = 0;
            }
        }
    }

    if (j > 0) {
        if (!isValidWord(dictionary, word)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

int main() {
    Dictionary dictionary;
    initializeDictionary(&dictionary);

    addWordToDictionary(&dictionary, "hello");
    addWordToDictionary(&dictionary, "world");

    char text[] = "Hello, world!";
    spellCheck(&dictionary, text);

    return 0;
}