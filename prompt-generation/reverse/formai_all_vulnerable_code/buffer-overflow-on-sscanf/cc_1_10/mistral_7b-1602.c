//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 256
#define MAX_TOKEN_LEN 50
#define MAX_NUM_TOKENS 128

typedef struct {
    char name[MAX_TOKEN_LEN];
    int line_num;
} Token;

void extract_token(char *line, Token *token, int *num_tokens) {
    int i = 0, j = 0, in_string = 0;
    char token_str[MAX_TOKEN_LEN];

    memset(token, 0, sizeof(Token));

    while (i < strlen(line)) {
        if (isspace(line[i])) {
            if (j > 0) {
                token->name[j] = '\0';
                j = 0;
            }
            continue;
        }

        if (line[i] == '(') {
            if (j > 0) {
                strcpy(token->name, token_str);
                sscanf(token_str, "%d", &token->line_num);
                *num_tokens = *num_tokens + 1;
                memset(token_str, 0, MAX_TOKEN_LEN);
            }
            i++;
            continue;
        }

        if (line[i] == '\'') {
            in_string = !in_string;
            i++;
            continue;
        }

        if (!in_string) {
            token_str[j++] = line[i];
        }

        i++;
    }

    if (j > 0) {
        strcpy(token->name, token_str);
        sscanf(token_str, "%d", &token->line_num);
        *num_tokens = *num_tokens + 1;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LEN];
    Token token;
    int num_tokens = 0, i;

    if (argc != 2) {
        printf("Usage: %s <c-file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, file)) {
        extract_token(line, &token, &num_tokens);
        if (num_tokens > 0 && strlen(token.name) > 0) {
            printf("Function: %s, Line Number: %d\n", token.name, token.line_num);
        }
        memset(&token, 0, sizeof(Token));
    }

    fclose(file);

    return 0;
}