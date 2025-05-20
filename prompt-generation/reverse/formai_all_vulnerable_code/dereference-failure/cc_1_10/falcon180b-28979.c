//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens!\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

char *read_line(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp);
    return strdup(line);
}

void parse_line(char *line, char delimiter) {
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        char *name = strtok(token, "=");
        char *value = strtok(NULL, "\n");
        if (name!= NULL && value!= NULL) {
            add_token(name, value);
        }
        token = strtok(NULL, delimiter);
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    char *line = read_line(fp);
    while (line!= NULL) {
        parse_line(line, ',');
        line = read_line(fp);
    }

    print_tokens();

    fclose(fp);
    return 0;
}