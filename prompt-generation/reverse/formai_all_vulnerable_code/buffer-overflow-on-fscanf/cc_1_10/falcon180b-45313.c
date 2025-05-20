//Falcon-180B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_STRING_LENGTH 1000
#define MAX_NUM_PATTERNS 100

typedef struct {
    char pattern[MAX_PATTERN_LENGTH];
    int count;
} Pattern;

int main() {
    FILE *inputFile;
    char inputString[MAX_STRING_LENGTH];
    int numPatterns = 0;
    Pattern patterns[MAX_NUM_PATTERNS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read in patterns from input file
    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        if (numPatterns >= MAX_NUM_PATTERNS) {
            printf("Error: Too many patterns.\n");
            exit(1);
        }
        strcpy(patterns[numPatterns].pattern, inputString);
        patterns[numPatterns].count = 0;
        numPatterns++;
    }

    fclose(inputFile);

    // Count occurrences of patterns in input file
    rewind(inputFile);
    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        int i;
        for (i = 0; i < numPatterns; i++) {
            if (strstr(inputString, patterns[i].pattern)!= NULL) {
                patterns[i].count++;
            }
        }
    }

    fclose(inputFile);

    // Print out results
    printf("Pattern\tCount\n");
    for (int i = 0; i < numPatterns; i++) {
        printf("%s\t%d\n", patterns[i].pattern, patterns[i].count);
    }

    return 0;
}