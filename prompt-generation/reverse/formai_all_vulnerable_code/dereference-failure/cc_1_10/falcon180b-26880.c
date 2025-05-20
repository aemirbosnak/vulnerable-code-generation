//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *token;
    int line_number;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int num_tokens;
} Tokenizer;

void init_tokenizer(Tokenizer *tokenizer) {
    tokenizer->num_tokens = 0;
}

void add_token(Tokenizer *tokenizer, char *token, int line_number) {
    if (tokenizer->num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens!\n");
        exit(1);
    }
    tokenizer->tokens[tokenizer->num_tokens].token = strdup(token);
    tokenizer->tokens[tokenizer->num_tokens].line_number = line_number;
    tokenizer->num_tokens++;
}

int main() {
    FILE *fp;
    char line[256];
    char *token;
    Tokenizer tokenizer;

    init_tokenizer(&tokenizer);

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int line_number = 1;
        char *pos = line;
        while ((token = strtok_r(pos, " \t\r\n", &pos))!= NULL) {
            add_token(&tokenizer, token, line_number);
            line_number++;
        }
    }

    fclose(fp);

    printf("Name: %s\n", tokenizer.tokens[0].token);
    printf("Address: %s\n", tokenizer.tokens[1].token);
    printf("Phone: %s\n", tokenizer.tokens[2].token);
    printf("Email: %s\n", tokenizer.tokens[3].token);

    return 0;
}