//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 10

typedef struct {
    char word[MAX_WORD_SIZE];
    int frequency;
} DictionaryEntry;

int main() {
    char input[MAX_WORD_SIZE];
    char dictionaryFile[MAX_WORD_SIZE];
    FILE *dictionary;
    int dictionarySize = 0;
    DictionaryEntry dictionaryEntries[MAX_DICTIONARY_SIZE];
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_SIZE];
    int numSuggestions = 0;

    printf("Enter dictionary file name: ");
    scanf("%s", dictionaryFile);

    dictionary = fopen(dictionaryFile, "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionary, "%s %d\n", dictionaryEntries[dictionarySize].word, &dictionaryEntries[dictionarySize].frequency) == 2) {
        dictionarySize++;
        if (dictionarySize == MAX_DICTIONARY_SIZE) {
            break;
        }
    }

    fclose(dictionary);

    while (1) {
        printf("Enter word to check: ");
        scanf("%s", input);

        int i = 0;
        while (i < dictionarySize && strcmp(dictionaryEntries[i].word, input)!= 0) {
            i++;
        }

        if (i == dictionarySize) {
            printf("Word not found in dictionary.\n");
        } else {
            printf("%s is a valid word.\n", input);
        }

        if (numSuggestions > 0) {
            printf("Did you mean:\n");
            for (int j = 0; j < numSuggestions; j++) {
                printf("%s\n", suggestions[j]);
            }
        }

        numSuggestions = 0;
    }

    return 0;
}