//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define ALIEN_VOCABULARY_SIZE 1000
#define ALIEN_WORD_LENGTH 10

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[ALIEN_WORD_LENGTH];
} Vocabulary;

void loadVocabulary(Vocabulary vocabulary[], int size) {
    FILE *file = fopen("vocabulary.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open vocabulary file.\n");
        exit(1);
    }

    int count = 0;
    while (count < size && fscanf(file, "%s %s", vocabulary[count].english, vocabulary[count].alien) == 2) {
        count++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        exit(1);
    }

    Vocabulary vocabulary[MAX_WORDS];
    loadVocabulary(vocabulary, ALIEN_VOCABULARY_SIZE);

    char sentence[MAX_WORD_LENGTH];
    strcpy(sentence, argv[1]);

    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        Vocabulary *translation = NULL;

        for (int i = 0; i < ALIEN_VOCABULARY_SIZE; i++) {
            if (strcmp(word, vocabulary[i].english) == 0) {
                translation = &vocabulary[i];
                break;
            }
        }

        if (translation == NULL) {
            printf("Unknown word: %s\n", word);
        } else {
            printf("%s -> %s\n", word, translation->alien);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}