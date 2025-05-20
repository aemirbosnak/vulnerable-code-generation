//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void parse_line(char *line) {
    char *token;
    char *key = NULL;
    char *value = NULL;
    int in_key = 0;
    int in_value = 0;

    for (token = strtok(line, " "); token!= NULL; token = strtok(NULL, " ")) {
        if (in_key) {
            strcat(key, " ");
            strcat(key, token);
        } else if (in_value) {
            strcat(value, " ");
            strcat(value, token);
        } else if (strcmp(token, "name") == 0) {
            in_key = 1;
        } else if (strcmp(token, "=") == 0) {
            in_key = 0;
            in_value = 1;
        }
    }

    if (in_key) {
        printf("Error: Missing value for key '%s'\n", key);
        exit(1);
    }

    add_token(key, value);
}

void print_tokens() {
    int i;
    for (i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open resume.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        parse_line(line);
    }

    fclose(fp);
    print_tokens();

    return 0;
}