//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 256
#define MAX_WORD_LEN 64

typedef struct {
    char *name;
    char *value;
} token_t;

token_t *tokens;
int num_tokens;

char *line;
int line_num;

void init_tokens() {
    tokens = (token_t *)malloc(MAX_TOKENS * sizeof(token_t));
    num_tokens = 0;
}

void init_line() {
    line = (char *)malloc(MAX_LINE_LEN * sizeof(char));
    line_num = 0;
}

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
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
    init_tokens();
    init_line();

    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char line_buf[MAX_LINE_LEN];
    while (fgets(line_buf, MAX_LINE_LEN, fp)!= NULL) {
        strcat(line, line_buf);
        line_num++;
    }
    fclose(fp);

    char *p = line;
    char *word = strtok(p, " \t\n\r\f");
    while (word!= NULL) {
        if (strlen(word) > MAX_WORD_LEN) {
            printf("Error: Word too long\n");
            exit(1);
        }
        add_token(word, "");
        word = strtok(NULL, " \t\n\r\f");
    }

    print_tokens();

    free(line);
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    free(tokens);

    return 0;
}