//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

static char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

static Token *tokenize(const char *input) {
    Token *tokens, *token;
    int capacity = 16, size = 0;
    char *start, *end;
    
    tokens = malloc(capacity * sizeof(Token));
    if (tokens == NULL) {
        return NULL;
    }
    
    start = (char *)input;
    while (*start != '\0') {
        if (isspace(*start)) {
            start++;
            continue;
        }
        
        if (*start == '\"' || *start == '\'') {
            end = start + 1;
            while (*end != *start && *end != '\0') {
                end++;
            }
            if (*end == '\0') {
                free(tokens);
                return NULL;
            }
            
            token = &tokens[size++];
            token->type = TOKEN_STRING;
            token->value = strndup(start + 1, end - start - 1);
            if (token->value == NULL) {
                free(tokens);
                return NULL;
            }
            
            start = end + 1;
            continue;
        }
        
        if (isdigit(*start)) {
            end = start + 1;
            while (isdigit(*end)) {
                end++;
            }
            if (*end == '.') {
                end++;
                while (isdigit(*end)) {
                    end++;
                }
            }
            if (*end == 'e' || *end == 'E') {
                end++;
                if (*end == '+' || *end == '-') {
                    end++;
                }
                while (isdigit(*end)) {
                    end++;
                }
            }
            
            token = &tokens[size++];
            token->type = TOKEN_NUMBER;
            token->value = strndup(start, end - start);
            if (token->value == NULL) {
                free(tokens);
                return NULL;
            }
            
            start = end;
            continue;
        }
        
        if (isalpha(*start) || *start == '_') {
            end = start + 1;
            while (isalnum(*end) || *end == '_') {
                end++;
            }
            
            int i;
            for (i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
                if (strlen(keywords[i]) == end - start && strncmp(keywords[i], start, end - start) == 0) {
                    token = &tokens[size++];
                    token->type = TOKEN_KEYWORD;
                    token->value = strdup(keywords[i]);
                    if (token->value == NULL) {
                        free(tokens);
                        return NULL;
                    }
                    
                    start = end;
                    break;
                }
            }
            
            if (i == sizeof(keywords) / sizeof(char *)) {
                token = &tokens[size++];
                token->type = TOKEN_IDENTIFIER;
                token->value = strndup(start, end - start);
                if (token->value == NULL) {
                    free(tokens);
                    return NULL;
                }
                
                start = end;
            }
            
            continue;
        }
        
        token = &tokens[size++];
        token->type = TOKEN_OPERATOR;
        token->value = strndup(start, 1);
        if (token->value == NULL) {
            free(tokens);
            return NULL;
        }
        
        start++;
    }
    
    token = &tokens[size++];
    token->type = TOKEN_EOF;
    token->value = NULL;
    
    return tokens;
}

static void free_tokens(Token *tokens) {
    if (tokens != NULL) {
        int i;
        for (i = 0; tokens[i].type != TOKEN_EOF; i++) {
            free(tokens[i].value);
        }
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    
    fseek(input, 0, SEEK_END);
    long size = ftell(input);
    fseek(input, 0, SEEK_SET);
    
    char *input_text = malloc(size + 1);
    if (input_text == NULL) {
        fclose(input);
        perror("malloc");
        return EXIT_FAILURE;
    }
    
    fread(input_text, 1, size, input);
    input_text[size] = '\0';
    
    fclose(input);
    
    Token *tokens = tokenize(input_text);
    if (tokens == NULL) {
        free(input_text);
        perror("tokenize");
        return EXIT_FAILURE;
    }
    
    int i;
    for (i = 0; tokens[i].type != TOKEN_EOF; i++) {
        switch (tokens[i].type) {
            case TOKEN_EOF:
                printf("EOF\n");
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", tokens[i].value);
                break;
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", tokens[i].value);
                break;
            case TOKEN_STRING:
                printf("STRING: %s\n", tokens[i].value);
                break;
            case TOKEN_OPERATOR:
                printf("OPERATOR: %s\n", tokens[i].value);
                break;
            case TOKEN_KEYWORD:
                printf("KEYWORD: %s\n", tokens[i].value);
                break;
        }
    }
    
    free_tokens(tokens);
    free(input_text);
    
    return EXIT_SUCCESS;
}