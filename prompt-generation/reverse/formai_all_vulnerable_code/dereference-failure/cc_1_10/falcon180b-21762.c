//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the vocabulary
#define VOCABULARY_SIZE 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} Vocabulary;

Vocabulary vocabulary[VOCABULARY_SIZE];
int vocabularySize = 0;

// Load the vocabulary from a file
void loadVocabulary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open vocabulary file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");

        if (english == NULL || alien == NULL) {
            printf("Error: invalid line in vocabulary file %s\n", filename);
            exit(1);
        }

        vocabulary[vocabularySize] = (Vocabulary) {.english = strdup(english),.alien = strdup(alien) };
        vocabularySize++;
    }

    fclose(file);
}

// Translate a sentence from English to Alien
void translateSentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < vocabularySize; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].alien);
                break;
            }
        }

        if (i == vocabularySize) {
            printf("unknown ");
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

// Main function
int main() {
    loadVocabulary("vocabulary.txt");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translateSentence(sentence);

    return 0;
}