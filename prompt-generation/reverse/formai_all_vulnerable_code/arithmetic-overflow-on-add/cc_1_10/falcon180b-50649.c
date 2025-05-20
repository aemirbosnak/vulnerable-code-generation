//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
            line[read] = '\0';
        }
    }

    return line;
}

void parse_tokens(char *line) {
    char *token;
    char *value = NULL;
    int i = 0;

    while ((token = strtok(line, " \t\r\n"))!= NULL) {
        if (num_tokens == MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }

        tokens[num_tokens].name = strdup(token);
        value = strchr(token, '=');

        if (value!= NULL) {
            *value = '\0';
            tokens[num_tokens].value = strdup(value + 1);
        } else {
            tokens[num_tokens].value = NULL;
        }

        ++num_tokens;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;

    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while ((line = read_line(fp))!= NULL) {
        parse_tokens(line);
    }

    fclose(fp);

    return 0;
}