//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define ALIEN_VOCABULARY_SIZE 1000
#define ALIEN_WORD_LENGTH 10

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[ALIEN_WORD_LENGTH];
} Vocabulary;

int main() {
    Vocabulary vocabulary[ALIEN_VOCABULARY_SIZE];
    int vocabularySize = 0;
    char input[MAX_SENTENCE_LENGTH];
    char *token;
    FILE *file;

    // Load alien language vocabulary
    file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open vocabulary file.\n");
        return 1;
    }
    while (fscanf(file, "%s %s", vocabulary[vocabularySize].english, vocabulary[vocabularySize].alien)!= EOF) {
        vocabularySize++;
    }
    fclose(file);

    // Translate input sentence
    printf("Enter a sentence to translate: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);
    token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < vocabularySize; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].alien);
                break;
            }
        }
        if (i == vocabularySize) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}