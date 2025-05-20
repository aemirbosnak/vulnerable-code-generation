//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 50

typedef struct {
    char *name;
    int value;
} token;

token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, int value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = value;
    num_tokens++;
}

int get_token_value(char *name) {
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].name, name) == 0) {
            return tokens[i].value;
        }
    }
    printf("Error: unknown token '%s'\n", name);
    exit(1);
}

int main() {
    add_token("meow", 1);
    add_token("purr", 2);
    add_token("hiss", 3);
    add_token("miaow", 4);
    add_token("nyan", 5);

    char input[MAX_TOKEN_SIZE];
    while (fgets(input, MAX_TOKEN_SIZE, stdin)!= NULL) {
        char *token_name = strtok(input, " ");
        if (token_name == NULL) {
            continue;
        }
        int token_value = get_token_value(token_name);
        printf("%d\n", token_value);
    }

    return 0;
}