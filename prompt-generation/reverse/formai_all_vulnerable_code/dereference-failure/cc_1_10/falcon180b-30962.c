//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_TOKEN_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = malloc(sizeof(Resume));
    resume->num_tokens = 0;
    resume->tokens = malloc(sizeof(Token));

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            Token *new_token = malloc(sizeof(Token));
            new_token->name = strdup(token);
            new_token->value = strdup(strtok(NULL, ":"));
            resume->tokens = realloc(resume->tokens, sizeof(Token) * ++resume->num_tokens);
            resume->tokens[resume->num_tokens - 1] = *new_token;

            token = strtok(NULL, ":");
        }
    }

    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_tokens; i++) {
        printf("%s: %s\n", resume->tokens[i].name, resume->tokens[i].value);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    Resume *resume = parse_resume(fp);
    fclose(fp);

    print_resume(resume);

    for (int i = 0; i < resume->num_tokens; i++) {
        free(resume->tokens[i].name);
        free(resume->tokens[i].value);
    }
    free(resume->tokens);
    free(resume);

    return 0;
}