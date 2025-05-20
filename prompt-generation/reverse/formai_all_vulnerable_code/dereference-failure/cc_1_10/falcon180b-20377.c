//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *name;
    char *value;
} token;

token tokens[MAX_TOKENS];
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
    char *p = line;
    char *key = NULL;
    char *value = NULL;

    while (*p!= '\0' && *p!= '=' && *p!= ':') {
        if (key == NULL) {
            key = p;
        }

        p++;
    }

    if (*p == '=') {
        p++;
    } else if (*p == ':') {
        p++;
    }

    value = p;

    while (*p!= '\0' && *p!= '\n' && *p!= '\r') {
        p++;
    }

    if (*p == '\n' || *p == '\r') {
        *p = '\0';
    }

    add_token(key, value);
}

void parse_file(FILE *fp) {
    char line[MAX_TOKEN_LEN];

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        parse_line(line);
    }
}

void print_tokens() {
    int i;

    for (i = 0; i < num_tokens; i++) {
        printf("%s=%s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    parse_file(fp);

    fclose(fp);

    print_tokens();

    return 0;
}