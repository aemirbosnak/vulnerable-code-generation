//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int translation;
} Word;

int main() {
    int numWords;
    char inputFile[50];
    char outputFile[50];
    FILE *input, *output;
    Word words[MAX_WORDS];

    // Get number of words in input file
    printf("Enter the number of words in the input file: ");
    scanf("%d", &numWords);

    // Get input file name
    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    // Get output file name
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    // Open input file
    input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read words from input file
    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(input, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        i++;
    }
    fclose(input);

    // Translate words
    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, "hello") == 0) {
            words[i].translation = 1;
        } else if (strcmp(words[i].word, "goodbye") == 0) {
            words[i].translation = 2;
        } else {
            words[i].translation = 0;
        }
    }

    // Write translated words to output file
    output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    for (i = 0; i < numWords; i++) {
        if (words[i].translation == 0) {
            fprintf(output, "UNKNOWN\n");
        } else {
            fprintf(output, "%d\n", words[i].translation);
        }
    }
    fclose(output);

    printf("Translation complete.\n");
    return 0;
}