//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 1024

typedef struct {
    char *text;
    int length;
} Token;

void add_token(Token *tokens, int count, char *text, int length) {
    if (count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[count].text = malloc(length + 1);
    strncpy(tokens[count].text, text, length);
    tokens[count].length = length;
    count++;
}

void print_tokens(Token *tokens, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", tokens[i].text);
    }
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Token tokens[MAX_TOKENS];
    int token_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *p = line;
        while (*p!= '\0') {
            if (*p == '<') {
                char *tag_start = p;
                while (*p!= '>' && *p!= '\0') {
                    p++;
                }
                if (*p == '>') {
                    p++;
                    int tag_length = p - tag_start - 1;
                    add_token(tokens, token_count, tag_start, tag_length);
                }
            } else if (*p == '&') {
                char *entity_start = p;
                while (*p!= ';' && *p!= '\0') {
                    p++;
                }
                if (*p == ';') {
                    p++;
                    int entity_length = p - entity_start - 1;
                    add_token(tokens, token_count, entity_start, entity_length);
                }
            } else {
                p++;
            }
        }
        token_count++;
    }

    fclose(input_file);

    print_tokens(tokens, token_count);

    return 0;
}