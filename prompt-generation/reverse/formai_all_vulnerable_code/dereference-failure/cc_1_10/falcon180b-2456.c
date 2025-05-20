//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 32

typedef struct {
    char *name;
    char *value;
} Token;

void add_token(Token *tokens, int num_tokens, char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }

    Token *new_tokens = realloc(tokens, sizeof(Token) * (num_tokens + 1));
    if (new_tokens == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    tokens = new_tokens;

    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);

    num_tokens++;
}

void print_tokens(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

void extract_metadata(FILE *file) {
    char line[MAX_LINE_SIZE];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *name = strtok(line, ": ");
        char *value = strtok(NULL, "\n");

        if (name == NULL || value == NULL) {
            continue;
        }

        add_token(tokens, num_tokens, name, value);
    }

    print_tokens(tokens, num_tokens);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    extract_metadata(file);

    fclose(file);

    return 0;
}