//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

typedef struct {
    Translation dictionary[MAX_DICTIONARY_SIZE];
    int count;
} Dictionary;

// Function to initialize the dictionary
void initDictionary(Dictionary *dict) {
    dict->count = 0;
}

// Function to add a translation to the dictionary
void addTranslation(Dictionary *dict, const char *english, const char *alien) {
    if (dict->count < MAX_DICTIONARY_SIZE) {
        strcpy(dict->dictionary[dict->count].english, english);
        strcpy(dict->dictionary[dict->count].alien, alien);
        dict->count++;
    } else {
        printf("Dictionary is full!\n");
    }
}

// Function to translate an English word to the alien language
const char* translateToAlien(Dictionary *dict, const char *english) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->dictionary[i].english, english) == 0) {
            return dict->dictionary[i].alien;
        }
    }
    return "Unknown"; // Return "Unknown" if no translation found
}

// Function to read a simple dictionary from a file
void loadDictionaryFromFile(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    char eng[MAX_WORD_LENGTH];
    char ali[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s", eng, ali) == 2) {
        addTranslation(dict, eng, ali);
    }

    fclose(file);
}

// Function to perform a simple test translation
void testTranslation(Dictionary *dict) {
    char input[MAX_WORD_LENGTH];
    printf("Enter an English word to translate (type 'exit' to quit):\n");
    while (1) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        const char *translation = translateToAlien(dict, input);
        printf("Translation: %s\n", translation);
    }
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    // Load dictionary
    loadDictionaryFromFile(&dict, "dictionary.txt");

    // Begin translation tests
    testTranslation(&dict);

    return 0;
}