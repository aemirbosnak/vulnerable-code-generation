//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[100];
    int numWords = 0;
    WordPair words[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, ",.?!:;\"'");
        while (token!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                exit(1);
            }
            words[numWords].english = strdup(token);
            srand(time(NULL));
            int length = rand() % (MAX_WORD_LENGTH - 3) + 3;
            char alienWord[length + 1];
            alienWord[length] = '\0';
            for (int i = 0; i < length; i++) {
                alienWord[i] = toupper(rand() % 26 + 'A');
            }
            words[numWords].alien = strdup(alienWord);
            token = strtok(NULL, ",.?!:;\"'");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].english, words[i].alien);
    }

    fclose(outputFile);

    return 0;
}