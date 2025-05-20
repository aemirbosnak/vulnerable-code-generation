//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    int frequency;
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    int numWords = 0;
    Word words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: Too many words.\n");
                    return 1;
                }
                strcpy(words[numWords].word, word);
                words[numWords].translation[0] = '\0';
                words[numWords].frequency = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            fprintf(outputFile, "%s %s %d\n", words[i].word, words[i].translation, words[i].frequency);
        }
    }

    fclose(outputFile);

    return 0;
}