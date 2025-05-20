//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CHARACTERS 100000
#define MAX_RUN_LENGTH 1000

typedef struct {
    char character;
    int runLength;
} Run;

typedef struct {
    int numRuns;
    Run *runs;
} RunTable;

void generateRuns(char *input, int inputLength, RunTable *runTable) {
    int i = 0, j = 0;
    runTable->numRuns = 0;

    while (i < inputLength) {
        if (j >= MAX_RUN_LENGTH) {
            j = 0;
            runTable->runs[runTable->numRuns].character = input[i];
            runTable->runs[runTable->numRuns].runLength = 1;
            runTable->numRuns++;
        }
        else if (input[i] == input[i + j]) {
            j++;
        }
        else {
            j = 0;
            runTable->runs[runTable->numRuns].character = input[i];
            runTable->runs[runTable->numRuns].runLength = 1;
            runTable->numRuns++;
        }
        i++;
    }
}

void generateCode(char *input, int inputLength, RunTable *runTable) {
    int i = 0, j = 0;
    while (i < inputLength) {
        if (j < runTable->numRuns && input[i] == runTable->runs[j].character) {
            i += runTable->runs[j].runLength;
            j++;
        }
        else {
            printf("%c", input[i]);
            i++;
        }
    }
}

int main() {
    char input[MAX_CHARACTERS];
    int inputLength;

    printf("Enter text to compress: ");
    fgets(input, MAX_CHARACTERS, stdin);
    inputLength = strlen(input);

    RunTable runTable;
    generateRuns(input, inputLength, &runTable);

    printf("Compressed text: ");
    generateCode(input, inputLength, &runTable);

    return 0;
}