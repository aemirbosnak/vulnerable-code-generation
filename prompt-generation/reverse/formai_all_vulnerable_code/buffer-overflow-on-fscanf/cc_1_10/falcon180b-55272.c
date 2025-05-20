//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int numDictionaryEntries = 0;

void loadDictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numDictionaryEntries && strcmp(dictionary[i].word, word)!= 0; i++) {
            // do nothing
        }
        if (i == numDictionaryEntries) {
            strcpy(dictionary[numDictionaryEntries].word, word);
            dictionary[numDictionaryEntries].count = 0;
            numDictionaryEntries++;
        } else {
            dictionary[i].count++;
        }
    }
    fclose(file);
}

int isWordInDictionary(char *word) {
    int i;
    for (i = 0; i < numDictionaryEntries; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void spellCheck(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = tolower(word[i]);
                }
            }
            if (!isWordInDictionary(word)) {
                printf("%s is not in the dictionary.\n", word);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

int main() {
    loadDictionary();
    spellCheck("input.txt");
    return 0;
}