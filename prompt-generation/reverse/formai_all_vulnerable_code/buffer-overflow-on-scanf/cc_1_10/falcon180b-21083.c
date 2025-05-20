//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *value;
    int length;
} Token;

void addToken(Token **tokens, int *numTokens, char *value) {
    if (*numTokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    (*tokens)[*numTokens] = (Token) {
       .value = strdup(value),
       .length = strlen(value)
    };
    (*numTokens)++;
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[1000];
    Token tokens[MAX_TOKENS];
    int numTokens = 0;

    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            addToken(&tokens, &numTokens, token);
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < numTokens; i++) {
        fprintf(outputFile, "%s\n", tokens[i].value);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}