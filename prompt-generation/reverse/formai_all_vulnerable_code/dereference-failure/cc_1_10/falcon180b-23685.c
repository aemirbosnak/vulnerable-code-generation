//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64

char *tokens[MAX_TOKENS];
int num_tokens;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1) {
        printf("Error reading line.\n");
        exit(1);
    }

    line[read - 1] = '\0';
    return line;
}

void tokenize(char *line) {
    char *token;
    int i = 0;

    num_tokens = 0;

    token = strtok(line, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Too many tokens.\n");
            exit(1);
        }

        tokens[num_tokens++] = strdup(token);

        token = strtok(NULL, " ");
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char *line;
    while ((line = read_line(fp))!= NULL) {
        tokenize(line);
        print_tokens();
    }

    fclose(fp);
    return 0;
}