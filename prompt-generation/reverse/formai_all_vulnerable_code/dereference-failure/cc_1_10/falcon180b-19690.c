//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char *english;
    char *alien;
} Translation;

int main() {
    FILE *inputFile, *outputFile;
    char inputLine[MAX_LINE_LENGTH];
    char *token;
    int lineNumber = 1;
    int numTranslations = 0;
    Translation translations[MAX_DICTIONARY_SIZE];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(inputLine, MAX_LINE_LENGTH, inputFile)!= NULL) {
        token = strtok(inputLine, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numTranslations; i++) {
                if (strcmp(token, translations[i].english) == 0) {
                    fprintf(outputFile, "%s ", translations[i].alien);
                    break;
                }
            }
            if (i == numTranslations) {
                if (numTranslations >= MAX_DICTIONARY_SIZE) {
                    printf("Dictionary is full.\n");
                    exit(1);
                }
                translations[numTranslations].english = strdup(token);
                translations[numTranslations].alien = "";
                printf("Enter alien translation for %s: ", token);
                fgets(inputLine, MAX_LINE_LENGTH, stdin);
                translations[numTranslations].alien = strdup(inputLine);
                numTranslations++;
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}