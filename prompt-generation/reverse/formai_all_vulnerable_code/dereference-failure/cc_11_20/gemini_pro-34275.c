//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON token types
typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT,
} JSON_TYPE;

// JSON token data
typedef struct JSON_TOKEN {
    JSON_TYPE type;
    union {
        int boolean;
        double number;
        char *string;
    } data;
} JSON_TOKEN;

// JSON parser state
typedef struct JSON_PARSER {
    char *input;
    char *current;
    JSON_TOKEN token;
} JSON_PARSER;

// Parse a JSON string
int json_parse(JSON_PARSER *parser) {
    // Skip whitespace
    while (*parser->current == ' ' || *parser->current == '\t' || *parser->current == '\n' || *parser->current == '\r') {
        parser->current++;
    }

    // Check for the start of a token
    switch (*parser->current) {
        case 'n': // null
            parser->token.type = JSON_NULL;
            while (*parser->current != 'l' && *parser->current != '\0') {
                parser->current++;
            }
            if (*parser->current != 'l') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 'l' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            break;

        case 't': // true
            parser->token.type = JSON_BOOL;
            parser->token.data.boolean = 1;
            while (*parser->current != 'r' && *parser->current != '\0') {
                parser->current++;
            }
            if (*parser->current != 'r') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 'u' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 'e' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            break;

        case 'f': // false
            parser->token.type = JSON_BOOL;
            parser->token.data.boolean = 0;
            while (*parser->current != 'a' && *parser->current != '\0') {
                parser->current++;
            }
            if (*parser->current != 'a') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 'l' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 's' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            if (*parser->current != 'e' && *parser->current != '\0') {
                return -1;
            }
            parser->current++;
            break;

        case '"': // string
            parser->token.type = JSON_STRING;
            parser->token.data.string = parser->current + 1;
            while (*parser->current != '"' && *parser->current != '\0') {
                parser->current++;
            }
            if (*parser->current != '"') {
                return -1;
            }
            *parser->current = '\0';
            parser->current++;
            break;

        case '[': // array
            parser->token.type = JSON_ARRAY;
            parser->current++;
            break;

        case '{': // object
            parser->token.type = JSON_OBJECT;
            parser->current++;
            break;

        default: // error
            return -1;
    }

    return 0;
}

// Print a JSON token
void json_print_token(JSON_TOKEN *token) {
    switch (token->type) {
        case JSON_NULL:
            printf("null");
            break;

        case JSON_BOOL:
            printf("%s", token->data.boolean ? "true" : "false");
            break;

        case JSON_NUMBER:
            printf("%f", token->data.number);
            break;

        case JSON_STRING:
            printf("\"%s\"", token->data.string);
            break;

        case JSON_ARRAY:
            printf("[");
            break;

        case JSON_OBJECT:
            printf("{");
            break;
    }
}

// Parse and print a JSON string
int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30}";

    JSON_PARSER parser;
    parser.input = json;
    parser.current = json;

    while (json_parse(&parser) == 0) {
        json_print_token(&parser.token);
    }

    return 0;
}