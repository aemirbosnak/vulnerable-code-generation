//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 1024

typedef enum {
    TOK_NONE,
    TOK_CURLY_OPEN,
    TOK_CURLY_CLOSE,
    TOK_SQUARE_OPEN,
    TOK_SQUARE_CLOSE,
    TOK_COLON,
    TOK_COMMA,
    TOK_STRING,
    TOK_NUMBER,
    TOK_TRUE,
    TOK_FALSE,
    TOK_NULL,
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

typedef struct {
    char *input;
    int pos;
    token current_token;
} parser;

token get_next_token(parser *p) {
    p->current_token.type = TOK_NONE;
    p->current_token.value = NULL;

    // Skip whitespace
    while (p->input[p->pos] == ' ' || p->input[p->pos] == '\t' || p->input[p->pos] == '\n' || p->input[p->pos] == '\r') {
        p->pos++;
    }

    // Get next character
    char c = p->input[p->pos++];

    switch (c) {
        case '{':
            p->current_token.type = TOK_CURLY_OPEN;
            break;
        case '}':
            p->current_token.type = TOK_CURLY_CLOSE;
            break;
        case '[':
            p->current_token.type = TOK_SQUARE_OPEN;
            break;
        case ']':
            p->current_token.type = TOK_SQUARE_CLOSE;
            break;
        case ':':
            p->current_token.type = TOK_COLON;
            break;
        case ',':
            p->current_token.type = TOK_COMMA;
            break;
        case '"': {
            // Get string value
            char *value = malloc(MAX_TOKEN_SIZE);
            int i = 0;
            while (p->input[p->pos] != '"' && p->input[p->pos] != '\0') {
                value[i++] = p->input[p->pos++];
            }
            value[i] = '\0';
            p->current_token.type = TOK_STRING;
            p->current_token.value = value;
            break;
        }
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '-': {
            // Get number value
            char *value = malloc(MAX_TOKEN_SIZE);
            int i = 0;
            while (p->input[p->pos] != ',' && p->input[p->pos] != '}' && p->input[p->pos] != ']' && p->input[p->pos] != '\0') {
                value[i++] = p->input[p->pos++];
            }
            value[i] = '\0';
            p->current_token.type = TOK_NUMBER;
            p->current_token.value = value;
            break;
        }
        case 't':
            if (strncmp(p->input + p->pos, "true", 4) == 0) {
                p->current_token.type = TOK_TRUE;
                p->pos += 4;
            }
            break;
        case 'f':
            if (strncmp(p->input + p->pos, "false", 5) == 0) {
                p->current_token.type = TOK_FALSE;
                p->pos += 5;
            }
            break;
        case 'n':
            if (strncmp(p->input + p->pos, "null", 4) == 0) {
                p->current_token.type = TOK_NULL;
                p->pos += 4;
            }
            break;
    }

    return p->current_token;
}

void print_json(token *token) {
    switch (token->type) {
        case TOK_CURLY_OPEN:
        case TOK_CURLY_CLOSE:
        case TOK_SQUARE_OPEN:
        case TOK_SQUARE_CLOSE:
        case TOK_COLON:
        case TOK_COMMA:
            printf("%c", token->value[0]);
            break;
        case TOK_STRING:
            printf("\"%s\"", token->value);
            break;
        case TOK_NUMBER:
            printf("%s", token->value);
            break;
        case TOK_TRUE:
            printf("true");
            break;
        case TOK_FALSE:
            printf("false");
            break;
        case TOK_NULL:
            printf("null");
            break;
    }
}

int main() {
    // Get JSON input from user
    char *input = malloc(1024);
    printf("Enter JSON input: ");
    fgets(input, 1024, stdin);

    // Create parser
    parser p;
    p.input = input;
    p.pos = 0;

    // Parse JSON input
    while (p.current_token.type != TOK_NONE) {
        p.current_token = get_next_token(&p);
        print_json(&p.current_token);
    }

    printf("\n");

    // Free memory
    free(input);

    return 0;
}