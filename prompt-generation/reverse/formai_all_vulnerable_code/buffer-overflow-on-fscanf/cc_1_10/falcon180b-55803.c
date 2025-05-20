//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency words[MAX_WORD_COUNT];
    int wordCount;
} Dictionary;

void loadDictionary(Dictionary* dict, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wf;
    while (fscanf(file, "%s %d", word, &wf.frequency) == 2) {
        strcpy(wf.word, word);
        dict->words[dict->wordCount++] = wf;
    }

    fclose(file);
}

void saveDictionary(const Dictionary* dict, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open dictionary file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < dict->wordCount; i++) {
        fprintf(file, "%s %d\n", dict->words[i].word, dict->words[i].frequency);
    }

    fclose(file);
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* wfA = (const WordFrequency*)a;
    const WordFrequency* wfB = (const WordFrequency*)b;

    return strcmp(wfA->word, wfB->word);
}

void spellCheck(const Dictionary* dict, const char* text) {
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        char* token = strtok(word, ",.?!;:");
        while (token!= NULL) {
            WordFrequency* wf = bsearch(token, dict->words, dict->wordCount, sizeof(WordFrequency), compareWords);
            if (wf == NULL) {
                printf("Unknown word: %s\n", token);
            }

            token = strtok(NULL, ",.?!;:");
        }
    }
}

int main() {
    Dictionary dict;
    loadDictionary(&dict, "dictionary.txt");

    printf("Enter text to spell check:\n");
    spellCheck(&dict, stdin);

    saveDictionary(&dict, "dictionary.txt");

    return 0;
}