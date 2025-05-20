//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *value;
    int length;
} Token;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[1000];
    char *token;
    Token tokens[MAX_TOKENS];
    int numTokens = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (numTokens >= MAX_TOKENS) {
                printf("Error: Too many tokens\n");
                return 1;
            }
            tokens[numTokens].value = malloc(MAX_TOKEN_LENGTH * sizeof(char));
            strncpy(tokens[numTokens].value, token, MAX_TOKEN_LENGTH);
            tokens[numTokens].length = strlen(token);
            numTokens++;
            token = strtok(NULL, " ");
        }
    }

    for (i = 0; i < numTokens; i++) {
        printf("Token %d: %s\n", i, tokens[i].value);
    }

    for (i = 0; i < numTokens; i++) {
        free(tokens[i].value);
    }

    fclose(inputFile);

    return 0;
}