//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000
#define MAX_SUGGESTIONS 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool isCorrect;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int numEntries = 0;

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numEntries >= MAX_DICTIONARY_SIZE) {
            printf("Warning: Dictionary is full. Ignoring entry: %s\n", word);
            continue;
        }

        dictionary[numEntries].word[0] = tolower(word[0]);
        strcpy(dictionary[numEntries].word + 1, word + 1);
        dictionary[numEntries].isCorrect = true;
        numEntries++;
    }

    fclose(file);
}

void suggestCorrections(const char* word) {
    int numSuggestions = 0;

    for (int i = 0; i < numEntries; i++) {
        if (strncmp(dictionary[i].word, word, strlen(word)) == 0) {
            printf("%s\n", dictionary[i].word);
            numSuggestions++;

            if (numSuggestions >= MAX_SUGGESTIONS) {
                break;
            }
        }
    }
}

int main() {
    loadDictionary("dictionary.txt");

    char sentence[1000];
    printf("Enter a sentence to check spelling:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char word[MAX_WORD_LENGTH];
    char* token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        strcpy(word, token);
        suggestCorrections(word);
        token = strtok(NULL, ",.!?;:");
    }

    return 0;
}