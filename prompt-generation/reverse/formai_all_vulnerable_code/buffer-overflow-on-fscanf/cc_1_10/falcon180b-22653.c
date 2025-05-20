//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 10

typedef struct {
    char word[MAX_WORD_SIZE];
    int frequency;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int numWordsInDictionary = 0;

void loadDictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        int frequency = 1;
        for (int i = 0; i < numWordsInDictionary; i++) {
            if (strcmp(dictionary[i].word, word) == 0) {
                frequency = dictionary[i].frequency + 1;
                break;
            }
        }
        if (numWordsInDictionary < MAX_DICTIONARY_SIZE) {
            strcpy(dictionary[numWordsInDictionary].word, word);
            dictionary[numWordsInDictionary].frequency = frequency;
            numWordsInDictionary++;
        }
    }
    fclose(file);
}

int compareStrings(const void* a, const void* b) {
    DictionaryEntry* entryA = (DictionaryEntry*)a;
    DictionaryEntry* entryB = (DictionaryEntry*)b;
    return strcmp(entryA->word, entryB->word);
}

void suggestCorrections(char* word, int* suggestions, int numSuggestions) {
    int numMatches = 0;
    for (int i = 0; i < numWordsInDictionary; i++) {
        if (strcmp(dictionary[i].word, word)!= 0) {
            if (numMatches < numSuggestions) {
                suggestions[numMatches] = i;
                numMatches++;
            }
        }
    }
    qsort(suggestions, numMatches, sizeof(int), compareStrings);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    loadDictionary(argv[1]);
    char word[MAX_WORD_SIZE];
    while (fgets(word, MAX_WORD_SIZE, stdin)!= NULL) {
        int numSuggestions = 0;
        int suggestions[MAX_SUGGESTIONS];
        suggestCorrections(word, suggestions, MAX_SUGGESTIONS);
        if (numSuggestions > 0) {
            printf("Did you mean: ");
            for (int i = 0; i < numSuggestions; i++) {
                DictionaryEntry* entry = &dictionary[suggestions[i]];
                printf("%s (%d)\n", entry->word, entry->frequency);
            }
        } else {
            printf("No suggestions.\n");
        }
    }
    return 0;
}