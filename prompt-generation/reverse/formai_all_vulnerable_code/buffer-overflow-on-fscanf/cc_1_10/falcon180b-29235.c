//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define ALIEN_DICTIONARY_SIZE 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} TranslationPair;

TranslationPair dictionary[ALIEN_DICTIONARY_SIZE];
int numPairs = 0;

void loadDictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s\n", line, line)!= EOF) {
        strcpy(dictionary[numPairs].english, line);
        strcpy(dictionary[numPairs].alien, line);
        numPairs++;
    }

    fclose(file);
}

int searchDictionary(char *word) {
    int i = 0;
    while (i < numPairs) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void translate(char *input) {
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int index = searchDictionary(token);
        if (index!= -1) {
            printf("%s ", dictionary[index].alien);
        } else {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    loadDictionary();

    char input[MAX_WORDS * MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    translate(input);

    return 0;
}