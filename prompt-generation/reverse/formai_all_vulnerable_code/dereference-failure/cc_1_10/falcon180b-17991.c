//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_VOCABULARY_SIZE 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

Vocabulary vocabulary[ALIEN_VOCABULARY_SIZE];
int vocabularySize = 0;

void loadVocabulary(const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char* englishWord = strtok(line, " ");
        char* alienWord = strtok(NULL, " ");
        strcpy(vocabulary[vocabularySize].english, englishWord);
        strcpy(vocabulary[vocabularySize].alien, alienWord);
        vocabularySize++;
    }
    fclose(file);
}

void saveVocabulary(const char* filename) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < vocabularySize; i++) {
        fprintf(file, "%s %s\n", vocabulary[i].english, vocabulary[i].alien);
    }
    fclose(file);
}

char* translateWord(const char* word) {
    for (int i = 0; i < vocabularySize; i++) {
        if (strcmp(vocabulary[i].english, word) == 0) {
            return vocabulary[i].alien;
        }
    }
    return NULL;
}

int main() {
    loadVocabulary("vocabulary.txt");

    char input[MAX_WORD_LENGTH];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* translatedWord = translateWord(input);
        if (translatedWord!= NULL) {
            printf("%s\n", translatedWord);
        } else {
            printf("Unknown word: %s\n", input);
        }
    }

    saveVocabulary("vocabulary.txt");
    return 0;
}