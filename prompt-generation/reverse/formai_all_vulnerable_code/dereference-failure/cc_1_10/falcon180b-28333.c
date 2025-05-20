//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

struct token {
    char *str;
    int count;
};

struct token *tokens = NULL;
int num_tokens = 0;

void add_token(char *str) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        exit(1);
    }
    struct token *new_token = malloc(sizeof(struct token));
    new_token->str = strdup(str);
    new_token->count = 1;
    tokens[num_tokens++] = *new_token;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].str, tokens[i].count);
    }
}

int main() {
    char line[1024];
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                char word[MAX_TOKEN_LEN];
                int j = 0;
                while (isalpha(line[i])) {
                    word[j++] = tolower(line[i]);
                    i++;
                    if (j >= MAX_TOKEN_LEN) {
                        break;
                    }
                }
                word[j] = '\0';
                add_token(word);
            }
        }
    }
    print_tokens();
    return 0;
}