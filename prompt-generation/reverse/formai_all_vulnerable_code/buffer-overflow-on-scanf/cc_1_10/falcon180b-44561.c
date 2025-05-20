//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *token;
    int length;
} Token;

void parseResume(char *input) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Token tokens[MAX_TOKENS];
    int numTokens = 0;

    FILE *fp = fopen(input, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (numTokens >= MAX_TOKENS) {
                printf("Error: too many tokens.\n");
                exit(1);
            }
            tokens[numTokens].token = strdup(token);
            tokens[numTokens].length = strlen(token);
            numTokens++;
            token = strtok(NULL, " ");
        }
        free(line);
        line = NULL;
        len = 0;
    }

    for (int i = 0; i < numTokens; i++) {
        printf("%s (%d characters)\n", tokens[i].token, tokens[i].length);
    }

    fclose(fp);
    for (int i = 0; i < numTokens; i++) {
        free(tokens[i].token);
    }
}

int main() {
    char *input;
    printf("Enter the name of the input file: ");
    scanf("%s", input);
    parseResume(input);

    return 0;
}