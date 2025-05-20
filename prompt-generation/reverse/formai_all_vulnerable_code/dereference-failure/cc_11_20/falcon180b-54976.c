//Falcon-180B DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char *word;
    WordCount *wordCounts = malloc(MAX_NUM_WORDS * sizeof(WordCount));
    int numWords = 0;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int length = strlen(token);
            if (length < MAX_WORD_LENGTH) {
                for (int i = 0; i < length; i++) {
                    if (!isalpha(token[i])) {
                        token[i] = tolower(token[i]);
                    }
                }
                for (int i = 0; i < numWords; i++) {
                    if (strcmp(wordCounts[i].word, token) == 0) {
                        wordCounts[i].count++;
                        break;
                    }
                }
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);
    free(wordCounts);

    return 0;
}