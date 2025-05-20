//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1000 // maximum size of JSON input
#define MAX_STRING_SIZE 100 // maximum size of JSON string value

typedef enum {
    NONE,
    OBJECT_START,
    OBJECT_END,
    ARRAY_START,
    ARRAY_END,
    COMMA,
    COLON,
    STRING,
    NUMBER,
    BOOLEAN,
    NULL_VALUE
} JsonType;

typedef union {
    char string[MAX_STRING_SIZE];
    double number;
    int boolean;
} JsonValue;

typedef struct {
    JsonType type;
    JsonValue value;
} JsonToken;

JsonToken parseToken(char* input) {
    JsonToken token;
    char* str;
    switch (*input) {
        case '{':
            token.type = OBJECT_START;
            token.value.string[0] = '\0';
            break;
        case '}':
            token.type = OBJECT_END;
            token.value.string[0] = '\0';
            break;
        case '[':
            token.type = ARRAY_START;
            token.value.string[0] = '\0';
            break;
        case ']':
            token.type = ARRAY_END;
            token.value.string[0] = '\0';
            break;
        case ':':
            token.type = COLON;
            token.value.string[0] = '\0';
            break;
        case ',':
            token.type = COMMA;
            token.value.string[0] = '\0';
            break;
        case '\"':
            token.type = STRING;
            str = ++input;
            while (*input != '\"') {
                if (*input == '\\') {
                    input++;
                }
                input++;
            }
            strncpy(token.value.string, str, input - str);
            token.value.string[input - str] = '\0';
            break;
        case 't':
            token.type = BOOLEAN;
            token.value.boolean = 1;
            input += 4;
            break;
        case 'f':
            token.type = BOOLEAN;
            token.value.boolean = 0;
            input += 5;
            break;
        case 'n':
            token.type = NULL_VALUE;
            token.value.string[0] = '\0';
            input += 4;
            break;
        default:
            if (isdigit(*input) || *input == '-') {
                token.type = NUMBER;
                token.value.number = atof(input);
                while (isdigit(*input) || *input == '.' || *input == 'e' || *input == 'E' || *input == '-') {
                    input++;
                }
            } else {
                printf("Unexpected token: %c\n", *input);
                exit(0);
            }
    }
    return token;
}

JsonToken* parseJson(char* input) {
    JsonToken* tokens = (JsonToken*) malloc(sizeof(JsonToken) * MAX_JSON_SIZE);
    int tokenCount = 0;
    while (*input != '\0') {
        if (isspace(*input)) {
            input++;
        } else {
            tokens[tokenCount++] = parseToken(input);
            input += strlen(tokens[tokenCount - 1].value.string);
        }
    }
    tokens[tokenCount].type = NONE;
    return tokens;
}

int main() {
    char input[MAX_JSON_SIZE];
    printf("Enter a JSON string:\n");
    fgets(input, MAX_JSON_SIZE, stdin);
    input[strcspn(input, "\r\n")] = '\0'; // remove newline characters
    JsonToken* tokens = parseJson(input);
    printf("Parsed input:\n");
    int i = 0;
    while (tokens[i].type != NONE) {
        switch (tokens[i].type) {
            case OBJECT_START:
                printf("{ ");
                break;
            case OBJECT_END:
                printf("} ");
                break;
            case ARRAY_START:
                printf("[ ");
                break;
            case ARRAY_END:
                printf("] ");
                break;
            case COMMA:
                printf(", ");
                break;
            case COLON:
                printf(": ");
                break;
            case STRING:
                printf("\"%s\" ", tokens[i].value.string);
                break;
            case NUMBER:
                printf("%f ", tokens[i].value.number);
                break;
            case BOOLEAN:
                printf("%s ", tokens[i].value.boolean ? "true" : "false");
                break;
            case NULL_VALUE:
                printf("null ");
                break;
            default:
                break;
        }
        i++;
    }
    printf("\n");
    return 0;
}