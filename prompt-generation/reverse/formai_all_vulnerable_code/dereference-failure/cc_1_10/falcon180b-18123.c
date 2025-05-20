//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

void parse_line(char *line, token_t *tokens) {
    char *token = NULL;
    char *value = NULL;
    int i = 0;

    while ((token = strtok(line, ":"))!= NULL) {
        value = strtok(NULL, ":");

        if (i >= MAX_TOKENS) {
            printf("Error: too many tokens\n");
            exit(1);
        }

        tokens[i].name = strdup(token);
        tokens[i].value = strdup(value);
        i++;
    }
}

void print_tokens(token_t *tokens) {
    int i;

    for (i = 0; i < MAX_TOKENS; i++) {
        if (tokens[i].name!= NULL) {
            printf("%s = %s\n", tokens[i].name, tokens[i].value);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_TOKEN_LEN];
    token_t tokens[MAX_TOKENS];
    int i = 0;

    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        parse_line(line, tokens);
    }

    print_tokens(tokens);

    fclose(fp);
    return 0;
}