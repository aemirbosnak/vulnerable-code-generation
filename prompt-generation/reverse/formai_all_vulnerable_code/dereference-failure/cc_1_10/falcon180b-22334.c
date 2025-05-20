//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *name;
    char *value;
} Token;

Token tokens[MAX_TOKENS];
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
    char *token_start = line;
    char *token_end;
    while ((token_end = strchr(token_start, ','))) {
        *token_end = '\0';
        add_token(token_start, token_end + 1);
        token_start = token_end + 1;
    }
    add_token(token_start, NULL);
}

void parse_file(FILE *fp) {
    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, fp)) {
        line[strcspn(line, "\n")] = '\0';
        parse_line(line);
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Could not open file\n");
        return 1;
    }
    parse_file(fp);
    print_tokens();
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    return 0;
}