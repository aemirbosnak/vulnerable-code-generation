//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 256

typedef struct {
    char *text;
    int length;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int numTokens;
} Tokenizer;

void tokenizerInit(Tokenizer *tokenizer) {
    tokenizer->numTokens = 0;
}

void tokenizerAddToken(Tokenizer *tokenizer, const char *text, int length) {
    if (tokenizer->numTokens >= MAX_TOKENS) {
        fprintf(stderr, "Error: Too many tokens\n");
        exit(1);
    }

    Token *token = &tokenizer->tokens[tokenizer->numTokens];
    token->text = malloc(length + 1);
    strncpy(token->text, text, length);
    token->text[length] = '\0';
    token->length = length;

    tokenizer->numTokens++;
}

void tokenizerPrintTokens(const Tokenizer *tokenizer) {
    for (int i = 0; i < tokenizer->numTokens; i++) {
        printf("%s (%d)\n", tokenizer->tokens[i].text, tokenizer->tokens[i].length);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not open output file\n");
        fclose(inputFile);
        return 1;
    }

    Tokenizer tokenizer;
    tokenizerInit(&tokenizer);

    char buffer[MAX_TOKEN_LENGTH];
    while (fscanf(inputFile, "%64s", buffer)!= EOF) {
        int length = strlen(buffer);
        tokenizerAddToken(&tokenizer, buffer, length);
    }

    fclose(inputFile);

    for (int i = 0; i < tokenizer.numTokens; i++) {
        fprintf(outputFile, "%s\n", tokenizer.tokens[i].text);
    }

    fclose(outputFile);

    tokenizerPrintTokens(&tokenizer);

    return 0;
}