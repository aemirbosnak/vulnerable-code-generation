//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *name;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} Resume;

Resume *parse_resume(char *input) {
    Resume *result = (Resume *) malloc(sizeof(Resume));
    result->tokens = (Token *) malloc(MAX_TOKENS * sizeof(Token));
    result->num_tokens = 0;

    char *token = strtok(input, ",;:");
    while (token!= NULL) {
        if (result->num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }
        Token *new_token = (Token *) malloc(sizeof(Token));
        new_token->name = strdup(token);
        new_token->value = NULL;
        result->tokens[result->num_tokens] = *new_token;
        result->num_tokens++;

        token = strtok(NULL, ",;:");
    }

    return result;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_tokens; i++) {
        printf("%s: %s\n", resume->tokens[i].name, resume->tokens[i].value);
    }
}

int main() {
    char *input = "John Doe, 25, Software Developer, Java, C++, Python";
    Resume *resume = parse_resume(input);
    print_resume(resume);

    free(resume->tokens);
    free(resume);
    return 0;
}