//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define MAX_NUM_TOKENS 128

typedef struct {
    char *token;
    int length;
} token_t;

typedef struct {
    int num_tokens;
    token_t *tokens;
} token_list_t;

void tokenize(char *line, token_list_t *tokens) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (tokens->num_tokens >= MAX_NUM_TOKENS) {
            printf("Error: Too many tokens on line.\n");
            exit(1);
        }
        if (strlen(token) >= MAX_TOKEN_LENGTH) {
            printf("Error: Token is too long.\n");
            exit(1);
        }
        tokens->tokens[tokens->num_tokens] = (token_t) {
           .token = strdup(token),
           .length = strlen(token)
        };
        tokens->num_tokens++;
        token = strtok(NULL, " ");
    }
}

void execute_command(token_list_t *tokens) {
    if (tokens->num_tokens < 1) {
        printf("Error: No command specified.\n");
        exit(1);
    }
    char *command = tokens->tokens[0].token;
    if (strcmp(command, "exit") == 0) {
        exit(0);
    } else if (strcmp(command, "echo") == 0) {
        if (tokens->num_tokens < 2) {
            printf("Error: No message specified for echo command.\n");
            exit(1);
        }
        char *message = tokens->tokens[1].token;
        printf("%s\n", message);
    } else {
        printf("Error: Unknown command '%s'.\n", command);
        exit(1);
    }
}

int main() {
    token_list_t tokens;
    tokens.num_tokens = 0;
    tokens.tokens = malloc(MAX_NUM_TOKENS * sizeof(token_t));
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        tokenize(line, &tokens);
        execute_command(&tokens);
        tokens.num_tokens = 0;
    }
    free(tokens.tokens);
    return 0;
}