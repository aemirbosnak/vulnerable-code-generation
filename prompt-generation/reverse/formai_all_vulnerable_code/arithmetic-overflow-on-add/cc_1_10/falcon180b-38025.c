//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000
#define UNKNOWN_WORD -1

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency words[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

void loadDictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    dict->size = 0;
    while (fscanf(file, "%s %d", dict->words[dict->size].word, &dict->words[dict->size].frequency) == 2) {
        dict->size++;
    }

    fclose(file);
}

bool isWordInDictionary(Dictionary *dict, const char *word) {
    WordFrequency *entry = dict->words;
    int i = 0;

    while (i < dict->size && strcmp(entry[i].word, word) < 0) {
        i++;
    }

    if (i >= dict->size || strcmp(entry[i].word, word)!= 0) {
        return false;
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    Dictionary dict;
    loadDictionary(&dict, argv[1]);

    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        printf("Error: Could not open text file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, textFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int index = 0;
            while (index < dict.size && strcmp(dict.words[index].word, word) < 0) {
                index++;
            }

            if (index >= dict.size || strcmp(dict.words[index].word, word)!= 0) {
                printf("%s: %d\n", word, UNKNOWN_WORD);
            } else {
                printf("%s: %d\n", word, dict.words[index].frequency);
            }

            word = strtok(NULL, ",.?!;:");
        }
        printf("\n");
    }

    fclose(textFile);

    return 0;
}