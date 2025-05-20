//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: genious
// C Cat Language Translator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 100
#define MAX_TRANSLATION_LENGTH 100

typedef struct {
    char *word;
    char *translation;
} TranslationPair;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    TranslationPair *translationPairs = (TranslationPair *)malloc(MAX_WORD_COUNT * sizeof(TranslationPair));

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            token = strtok(NULL, " ");
            if (wordCount >= MAX_WORD_COUNT) {
                printf("Error: Maximum word count exceeded.\n");
                exit(1);
            }
            translationPairs[wordCount].word = strdup(word);
            printf("Enter translation for '%s': ", word);
            fgets(translationPairs[wordCount].translation, MAX_TRANSLATION_LENGTH, stdin);
            wordCount++;
        }
    }

    rewind(inputFile);

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            token = strtok(NULL, " ");
            int i;
            for (i = 0; i < wordCount; i++) {
                if (strcmp(word, translationPairs[i].word) == 0) {
                    fprintf(outputFile, "%s ", translationPairs[i].translation);
                    break;
                }
            }
            if (i == wordCount) {
                fprintf(outputFile, "%s ", word);
            }
        }
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}