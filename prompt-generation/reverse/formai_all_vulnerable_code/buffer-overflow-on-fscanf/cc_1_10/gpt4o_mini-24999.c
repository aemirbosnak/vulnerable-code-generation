//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

typedef struct {
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_WORDS];
int entryCount = 0;

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", dictionary[entryCount].english, dictionary[entryCount].alien) != EOF) {
        entryCount++;
        if (entryCount >= MAX_WORDS) {
            fprintf(stderr, "Dictionary file exceeds maximum number of words.\n");
            exit(EXIT_FAILURE);
        }
    }
    
    fclose(file);
}

void translateWord(const char *word, char *output) {
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            strcpy(output, dictionary[i].alien);
            return;
        }
    }
    strcpy(output, "UNKNOWN");
}

void translateSentence(const char *sentence, char *output) {
    char *token = strtok(sentence, " ");
    output[0] = '\0'; // Initialize output string

    while (token != NULL) {
        char alienWord[MAX_LENGTH];
        translateWord(token, alienWord);
        strcat(output, alienWord);
        strcat(output, " ");
        token = strtok(NULL, " ");
    }

    // Remove trailing space
    if (output[0] != '\0') {
        output[strlen(output) - 1] = '\0';
    }
}

int main() {
    char inputSentence[256];
    char translatedSentence[256];
    
    loadDictionary("alien_dictionary.txt");
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence in English: ");
    fgets(inputSentence, sizeof(inputSentence), stdin);
    
    // Remove trailing newline
    inputSentence[strcspn(inputSentence, "\n")] = 0;

    translateSentence(inputSentence, translatedSentence);
    
    printf("Translated to Alien Language: %s\n", translatedSentence);
    
    return 0;
}