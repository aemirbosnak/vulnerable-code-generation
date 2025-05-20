//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

Token *tokens = NULL;
int token_count = 0;

void add_token(char *name, char *value) {
    if (token_count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }

    Token *new_token = (Token*) malloc(sizeof(Token));
    new_token->name = strdup(name);
    new_token->value = strdup(value);

    tokens[token_count++] = *new_token;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    char *name = NULL;
    char *value = NULL;
    int in_section = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (strncmp(line, "[", 1) == 0) {
            if (name!= NULL) {
                add_token(name, value);
                name = NULL;
                value = NULL;
            }

            in_section = 1;
            continue;
        }

        if (strncmp(line, "]", 1) == 0) {
            in_section = 0;
            continue;
        }

        if (in_section) {
            int len = strlen(line);
            if (len > 0 && line[len - 1] == ':') {
                char *colon = strrchr(line, ':');
                *colon = '\0';

                if (name == NULL) {
                    name = strdup(line);
                } else {
                    value = strdup(colon + 1);
                }
            }
        }
    }

    if (name!= NULL) {
        add_token(name, value);
    }

    fclose(fp);

    for (int i = 0; i < token_count; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    return 0;
}