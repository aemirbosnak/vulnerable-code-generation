//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int numWords = 0;

void loadDictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading dictionary: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int frequency = 1;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(dictionary[i].word, word) == 0) {
                frequency = dictionary[i].frequency + 1;
                break;
            }
        }
        DictionaryEntry entry = {word, frequency};
        for (int i = 0; i < numWords; i++) {
            if (strcmp(dictionary[i].word, word) == 0 && dictionary[i].frequency < frequency) {
                dictionary[i] = entry;
                break;
            }
        }
        if (numWords < MAX_DICTIONARY_SIZE) {
            dictionary[numWords++] = entry;
        }
    }

    fclose(fp);
}

int findClosestMatch(char* word) {
    int minDistance = MAX_WORD_LENGTH;
    int closestMatch = -1;

    for (int i = 0; i < numWords; i++) {
        int distance = 0;
        for (int j = 0; j < strlen(dictionary[i].word) && j < strlen(word); j++) {
            if (tolower(dictionary[i].word[j])!= tolower(word[j])) {
                distance++;
            }
        }
        if (distance < minDistance) {
            minDistance = distance;
            closestMatch = i;
        }
    }

    return closestMatch;
}

void suggestCorrections(char* word) {
    int closestMatch = findClosestMatch(word);

    if (closestMatch == -1) {
        printf("No suggestions found.\n");
        return;
    }

    printf("Did you mean: %s?\n", dictionary[closestMatch].word);

    for (int i = 0; i < MAX_SUGGESTIONS && i < numWords; i++) {
        if (i!= closestMatch) {
            int distance = strlen(dictionary[i].word) - strlen(word);
            if (distance <= 2 && distance > 0) {
                printf(" %s\n", dictionary[i].word);
            }
        }
    }
}

int main() {
    loadDictionary("dictionary.txt");

    char sentence[MAX_WORD_LENGTH * 100];
    printf("Enter a sentence to check spelling: ");
    fgets(sentence, sizeof(sentence), stdin);

    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int wordLength = strlen(token);
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            suggestCorrections(token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}