//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

void loadDictionary(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN+1];
    while (fscanf(f, "%s", word)!= EOF) {
        DictionaryEntry entry;
        strcpy(entry.word, word);
        entry.count = 1;
        dictionary[dictionarySize++] = entry;
    }

    fclose(f);
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void checkSpelling(char* word) {
    char* correctedWord = NULL;
    int numCorrections = 0;

    DictionaryEntry* entry = bsearch(word, dictionary, dictionarySize, sizeof(DictionaryEntry), compareWords);
    if (entry == NULL) {
        correctedWord = word;
        numCorrections = 1;
    } else {
        correctedWord = entry->word;
    }

    if (numCorrections == 0) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly. Did you mean %s?\n", word, correctedWord);
    }
}

int main() {
    loadDictionary("dictionary.txt");

    char word[MAX_WORD_LEN+1];
    while (scanf(" %s", word)!= EOF) {
        checkSpelling(word);
    }

    return 0;
}