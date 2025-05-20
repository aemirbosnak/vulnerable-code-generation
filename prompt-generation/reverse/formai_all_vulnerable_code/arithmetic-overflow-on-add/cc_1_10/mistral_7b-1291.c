//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 128

typedef struct {
    char token[MAX_TOKEN_LENGTH];
    int count;
} TokenStat;

void tokenize_line(char line[], TokenStat tokens[]) {
    int i, j, token_index;
    char token[MAX_TOKEN_LENGTH];

    i = j = 0;
    while (i < strlen(line)) {
        while (isspace(line[i])) i++;

        token_index = 0;
        while (token_index < MAX_TOKEN_LENGTH && line[i] != ' ' && line[i] != '\t' && line[i] != '\0') {
            token[token_index++] = line[i++];
        }

        if (token_index > 0) {
            strcpy(tokens[j++].token, token);
            tokens[j - 1].count++;
        }

        while (isspace(line[i])) i++;
    }

    tokens[j].token[0] = '\0';
}

void print_token_stats(TokenStat tokens[], int num_tokens) {
    int i;

    for (i = 0; i < num_tokens; i++) {
        printf("%-16s %d\n", tokens[i].token, tokens[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    TokenStat tokens[MAX_TOKENS];
    int num_tokens = 0;

    file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        tokenize_line(line, tokens);
        num_tokens = (num_tokens < (int)(sizeof(tokens) / sizeof(TokenStat))) ? num_tokens + 1 : num_tokens;
    }

    fclose(file);

    print_token_stats(tokens, num_tokens);

    return 0;
}