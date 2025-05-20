//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} Token;

int tokenize(char *line, Token *tokens) {
    int i = 0;
    char *token = strtok(line, " \t\r\n");
    while (token!= NULL && i < MAX_TOKENS) {
        tokens[i].token = malloc(MAX_TOKEN_LEN);
        strncpy(tokens[i].token, token, MAX_TOKEN_LEN);
        tokens[i].token_len = strlen(token);
        i++;
        token = strtok(NULL, " \t\r\n");
    }
    return i;
}

int main() {
    char *line = NULL;
    char *resume = NULL;
    int resume_len = 0;
    char *token_value = NULL;
    int num_tokens = 0;
    Token tokens[MAX_TOKENS];

    // Read in the resume
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open resume file.\n");
        return 1;
    }
    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        resume_len += strlen(line);
        resume = realloc(resume, resume_len + 1);
        strcat(resume, line);
    }
    fclose(fp);

    // Tokenize the resume
    num_tokens = tokenize(resume, tokens);

    // Print out the tokens
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].token);
    }

    // Free memory
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].token);
    }
    free(tokens);
    free(resume);

    return 0;
}