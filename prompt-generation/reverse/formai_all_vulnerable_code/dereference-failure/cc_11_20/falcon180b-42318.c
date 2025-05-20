//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char* english;
    char* alien;
} Vocabulary;

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    Vocabulary vocabulary[MAX_VOCABULARY];
    int vocabularySize = 0;

    char line[MAX_WORD_LENGTH+1];
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < vocabularySize; i++) {
                if (strcmp(token, vocabulary[i].english) == 0) {
                    printf("Alien translation for '%s': %s\n", token, vocabulary[i].alien);
                    break;
                }
            }

            if (i == vocabularySize) {
                if (vocabularySize >= MAX_VOCABULARY) {
                    printf("Error: vocabulary is full.\n");
                    return 1;
                }

                vocabulary[vocabularySize].english = strdup(token);
                vocabulary[vocabularySize].alien = "";
                vocabularySize++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char* token = strtok(line, " ");
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
    }

    fclose(inputFile);

    return 0;
}