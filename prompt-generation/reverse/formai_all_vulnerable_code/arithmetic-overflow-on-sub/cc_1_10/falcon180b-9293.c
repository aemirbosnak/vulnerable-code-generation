//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *value;
    int line_number;
} Token;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1) {
        printf("Error reading line.\n");
        exit(1);
    }

    line[read-1] = '\0'; // remove newline character
    return line;
}

void tokenize(char *line, Token *tokens) {
    int i = 0;
    char *word = strtok(line, " ");
    while (word!= NULL && i < MAX_TOKENS) {
        if (strlen(word) > MAX_TOKEN_LENGTH) {
            printf("Token too long: %s\n", word);
            exit(1);
        }
        tokens[i].value = strdup(word);
        tokens[i].line_number = 1; // assume all tokens are on the same line
        i++;
        word = strtok(NULL, " ");
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

    char *line = NULL;
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    while ((line = read_line(fp))!= NULL) {
        tokenize(line, tokens);
        num_tokens += strlen(line);
    }

    fclose(fp);

    printf("Number of tokens: %d\n", num_tokens);

    return 0;
}