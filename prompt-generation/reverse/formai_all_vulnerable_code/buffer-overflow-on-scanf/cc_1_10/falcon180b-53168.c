//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

int parseResume(char *filename, Token *tokens) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int numTokens = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            if (numTokens >= MAX_TOKENS) {
                printf("Error: too many tokens\n");
                fclose(file);
                return 1;
            }
            tokens[numTokens].name = strdup(token);
            tokens[numTokens].value = strdup("");
            numTokens++;
            token = strtok(NULL, " \t\r\n");
        }
    }

    fclose(file);
    return 0;
}

void printTokens(Token *tokens, int numTokens) {
    int i;

    for (i = 0; i < numTokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    char filename[1024];
    Token tokens[MAX_TOKENS];
    int numTokens;

    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    numTokens = parseResume(filename, tokens);
    if (numTokens > 0) {
        printTokens(tokens, numTokens);
    }

    return 0;
}