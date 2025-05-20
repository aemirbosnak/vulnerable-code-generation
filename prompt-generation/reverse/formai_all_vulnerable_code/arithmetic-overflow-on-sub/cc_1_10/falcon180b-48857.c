//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *value;
    int line_number;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *value, int line_number) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].value = strdup(value);
    tokens[num_tokens].line_number = line_number;
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %s\n", tokens[i].line_number, tokens[i].value);
    }
}

char *read_line(FILE *file, int *line_number) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        *line_number += 1;
        return line;
    }

    if (line!= NULL) {
        free(line);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    int line_number = 1;
    char *line = read_line(file, &line_number);

    while (line!= NULL) {
        char *token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            add_token(token, line_number);
            token = strtok(NULL, " \t\r\n");
        }
        line = read_line(file, &line_number);
    }

    fclose(file);
    print_tokens();

    return 0;
}