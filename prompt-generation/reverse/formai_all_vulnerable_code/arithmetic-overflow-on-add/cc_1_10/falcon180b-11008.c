//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }
}

void writeWords(FILE *file, WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    readWords(inputFile, words);

    fclose(inputFile);

    char outputFilename[100];
    printf("Enter the name of the output file: ");
    scanf("%s", outputFilename);

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    writeWords(outputFile, words);

    fclose(outputFile);

    return 0;
}