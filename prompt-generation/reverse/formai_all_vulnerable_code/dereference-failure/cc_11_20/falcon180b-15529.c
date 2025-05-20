//Falcon-180B DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    WordCount words[1000];
    int numWords = 0;
    int i, j;
    char *word;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        numWords = 0;
        word = strtok(line, ",.!?;:");

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;

                if (numWords >= 1000) {
                    printf("Error: Too many words.\n");
                    exit(1);
                }
            }

            word = strtok(NULL, ",.!?;:");
        }

        for (i = 0; i < numWords; i++) {
            fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}