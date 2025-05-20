//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        dictionary[dictionarySize].word[0] = toupper(word[0]);
        strcpy(&dictionary[dictionarySize].word[1], word);
        dictionary[dictionarySize].frequency = 1;
        dictionarySize++;
    }

    fclose(file);
}

int compareDictionaryEntries(const void* a, const void* b) {
    DictionaryEntry* entryA = (DictionaryEntry*) a;
    DictionaryEntry* entryB = (DictionaryEntry*) b;

    return strcmp(entryA->word, entryB->word);
}

void suggestCorrections(const char* word) {
    if (dictionarySize == 0) {
        printf("No suggestions found.\n");
        return;
    }

    int matches = 0;
    int maxSuggestions = MAX_SUGGESTIONS;
    if (dictionarySize < maxSuggestions) {
        maxSuggestions = dictionarySize;
    }

    qsort(dictionary, dictionarySize, sizeof(DictionaryEntry), compareDictionaryEntries);

    for (int i = 0; i < maxSuggestions && i < dictionarySize; i++) {
        if (strcasecmp(word, dictionary[i].word) == 0) {
            printf("%s\n", dictionary[i].word);
            matches++;
        } else if (matches < maxSuggestions) {
            printf("%s\n", dictionary[i].word);
        }
    }
}

int main() {
    loadDictionary("dictionary.txt");

    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        char word[MAX_WORD_LENGTH];
        char* token = strtok(sentence, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            suggestCorrections(word);
            token = strtok(NULL, ",.?!;:");
        }
    }

    return 0;
}