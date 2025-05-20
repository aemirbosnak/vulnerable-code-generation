//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *value;
    int length;
} Token;

void addToken(Token *tokens, int numTokens, char *value, int length) {
    if (numTokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    tokens[numTokens].value = malloc(length + 1);
    strncpy(tokens[numTokens].value, value, length);
    tokens[numTokens].length = length;
    numTokens++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char *buffer = malloc(MAX_TOKEN_LENGTH);
    int bufferIndex = 0;
    int numTokens = 0;
    Token tokens[MAX_TOKENS];

    while (fscanf(file, "%s", buffer + bufferIndex)!= EOF) {
        int length = strlen(buffer);
        if (bufferIndex + length >= MAX_TOKEN_LENGTH) {
            printf("Error: Token too long.\n");
            exit(1);
        }
        addToken(tokens, numTokens, buffer, length);
        bufferIndex += length;
        bufferIndex += 1; // Add space for null terminator
    }

    fclose(file);

    printf("Number of tokens: %d\n", numTokens);
    for (int i = 0; i < numTokens; i++) {
        printf("%s (%d)\n", tokens[i].value, tokens[i].length);
    }

    free(buffer);
    for (int i = 0; i < numTokens; i++) {
        free(tokens[i].value);
    }

    return 0;
}