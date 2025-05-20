//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

bool loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open dictionary file.\n");
        return false;
    }

    char word[MAX_WORD_LENGTH];
    int frequency = 0;
    while (fscanf(file, "%s %d", word, &frequency) == 2) {
        if (dictionarySize >= MAX_DICTIONARY_SIZE) {
            printf("Error: dictionary is full.\n");
            fclose(file);
            return false;
        }

        strcpy(dictionary[dictionarySize].word, word);
        dictionary[dictionarySize].frequency = frequency;
        dictionarySize++;
    }

    fclose(file);
    return true;
}

bool isValidWord(const char* word) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }

    return true;
}

int getFrequency(const char* word) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].frequency;
        }
    }

    return 0;
}

int main() {
    const char* filename = "dictionary.txt";
    if (!loadDictionary(filename)) {
        return 1;
    }

    printf("Enter a string to check:\n");
    char input[1000];
    fgets(input, 1000, stdin);

    char* word = strtok(input, " ");
    while (word!= NULL) {
        if (!isValidWord(word)) {
            printf("Error: \"%s\" is not a valid word.\n", word);
        } else {
            int frequency = getFrequency(word);
            if (frequency == 0) {
                printf("Error: \"%s\" is not in the dictionary.\n", word);
            } else {
                printf("\"%s\" is in the dictionary with a frequency of %d.\n", word, frequency);
            }
        }

        word = strtok(NULL, " ");
    }

    return 0;
}