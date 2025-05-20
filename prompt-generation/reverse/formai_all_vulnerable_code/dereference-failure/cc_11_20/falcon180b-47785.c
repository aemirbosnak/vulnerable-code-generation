//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char line[100];
    Word words[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                return 1;
            }

            Word *currentWord = &words[numWords];
            currentWord->english = strdup(word);
            currentWord->cat = NULL;

            numWords++;

            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    for (int i = 0; i < numWords; i++) {
        Word *currentWord = &words[i];
        char *englishWord = currentWord->english;
        char *catWord = NULL;

        if (strcmp(englishWord, "hello") == 0) {
            catWord = "mewo";
        } else if (strcmp(englishWord, "world") == 0) {
            catWord = "werld";
        } else if (strcmp(englishWord, "cat") == 0) {
            catWord = "kat";
        } else if (strcmp(englishWord, "dog") == 0) {
            catWord = "dog";
        } else {
            printf("Warning: unknown word '%s'.\n", englishWord);
        }

        currentWord->cat = strdup(catWord);
    }

    for (int i = 0; i < numWords; i++) {
        Word *currentWord = &words[i];
        fprintf(outputFile, "%s %s\n", currentWord->english, currentWord->cat);
    }

    fclose(outputFile);

    return 0;
}