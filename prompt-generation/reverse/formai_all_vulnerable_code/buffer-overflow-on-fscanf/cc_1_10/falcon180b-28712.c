//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency words[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

void initializeDictionary(Dictionary *dict) {
    dict->size = 0;
}

void addWordToDictionary(Dictionary *dict, char *word) {
    if (dict->size >= MAX_DICTIONARY_SIZE) {
        printf("Dictionary is full.\n");
        return;
    }

    WordFrequency newWord;
    strcpy(newWord.word, word);
    newWord.frequency = 1;

    dict->words[dict->size++] = newWord;
}

int getWordFrequency(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return dict->words[i].frequency;
        }
    }

    return 0;
}

void printDictionary(Dictionary *dict) {
    printf("Dictionary:\n");
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->words[i].word, dict->words[i].frequency);
    }
}

void spellCheck(char *text, Dictionary *dict) {
    char word[MAX_WORD_LENGTH];
    int wordLength;

    while ((wordLength = fscanf(text, "%s", word))!= EOF) {
        if (wordLength == 0) {
            continue;
        }

        int frequency = getWordFrequency(dict, word);

        if (frequency == 0) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

int main() {
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    Dictionary dict;
    initializeDictionary(&dict);

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictFile, "%s", word)!= EOF) {
        addWordToDictionary(&dict, word);
    }

    fclose(dictFile);

    FILE *textFile = fopen("text.txt", "r");
    if (textFile == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    spellCheck(textFile, &dict);

    fclose(textFile);

    return 0;
}