//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} Token;

Token *tokens = NULL;
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }

    Token *new_token = malloc(sizeof(Token));
    new_token->name = strdup(name);
    new_token->value = strdup(value);

    tokens[num_tokens++] = *new_token;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        char *value = strtok(NULL, ":");
        if (value == NULL) {
            continue;
        }

        add_token(token, value);
    }

    fclose(fp);

    printf("Name: %s\n", tokens[0].value);
    printf("Email: %s\n", tokens[1].value);
    printf("Phone: %s\n", tokens[2].value);
    printf("Address: %s\n", tokens[3].value);

    for (int i = 4; i < num_tokens; i++) {
        printf("Skill: %s\n", tokens[i].value);
    }

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    free(tokens);

    return 0;
}