//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputFilename[50], outputFilename[50];
    char line[100];
    int numWords = 0;
    WordPair words[MAX_WORDS];

    // Prompt user for input and output filenames
    printf("Enter input filename: ");
    scanf("%s", inputFilename);
    printf("Enter output filename: ");
    scanf("%s", outputFilename);

    // Open input file for reading
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Read in English-Alien word pairs from input file
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(1);
        }
        words[numWords].english = strdup(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: missing alien word in input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(1);
        }
        words[numWords].alien = strdup(token);
        numWords++;
    }

    // Close input file
    fclose(inputFile);

    // Translate English words to Alien language
    for (int i = 0; i < numWords; i++) {
        char *englishWord = words[i].english;
        char *alienWord = words[i].alien;

        // Add your translation logic here

        strcpy(alienWord, "Alien translation of ");
        strcat(alienWord, englishWord);
    }

    // Write translated words to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].english, words[i].alien);
    }

    // Close output file
    fclose(outputFile);

    printf("Translation complete!\n");

    return 0;
}