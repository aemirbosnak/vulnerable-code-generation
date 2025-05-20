//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    FILE *dictFile;
    Word dict[MAX_WORDS];
    int numWords = 0;
    char input[100];
    char *token;

    // Load dictionary from file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictFile, "%s %s\n", dict[numWords].english, dict[numWords].cat)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            return 1;
        }
    }

    fclose(dictFile);

    // Translate user input
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, dict[i].english) == 0) {
                printf("%s ", dict[i].cat);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}