//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        return;
    }

    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);

    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[MAX_TOKEN_LEN];
    char *token;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        token = strtok(line, ":");
        while (token!= NULL) {
            add_token(token, strtok(NULL, ":"));
            token = strtok(NULL, ":");
        }
    }

    fclose(fp);
    print_tokens();

    return 0;
}