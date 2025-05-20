//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    WordTranslation dict[MAX_WORDS];
    int numWords = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictFile)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: Invalid line in dictionary file.\n");
            return 1;
        }

        strcpy(dict[numWords].word, word);
        strcpy(dict[numWords].translation, translation);
        numWords++;

        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary file is too large.\n");
            return 1;
        }
    }

    fclose(dictFile);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(input, " ");

        if (word == NULL) {
            printf("\n");
            continue;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(dict[i].word, word) == 0) {
                printf("%s -> %s\n", word, dict[i].translation);
                break;
            }
        }

        if (i == numWords) {
            printf("No translation found.\n");
        }
    }

    return 0;
}