//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1024
#define MAX_JSON_NESTING_DEPTH 32

enum json_type {
    JSON_TYPE_INVALID,
    JSON_TYPE_OBJECT_START,
    JSON_TYPE_OBJECT_END,
    JSON_TYPE_ARRAY_START,
    JSON_TYPE_ARRAY_END,
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL,
};

struct json_token {
    enum json_type type;
    char *value;
    size_t value_len;
};

int current_depth = 0;

struct json_token *parse_json_token(char *json_string) {
    struct json_token *token = malloc(sizeof(struct json_token));
    token->type = JSON_TYPE_INVALID;
    token->value = NULL;
    token->value_len = 0;

    char *ptr = json_string;
    while (*ptr != '\0') {
        switch (*ptr) {
            case '{':
                if (current_depth >= MAX_JSON_NESTING_DEPTH) {
                    printf("Error: Maximum nesting depth exceeded.\n");
                    return NULL;
                }
                token->type = JSON_TYPE_OBJECT_START;
                current_depth++;
                break;
            case '}':
                if (current_depth <= 0) {
                    printf("Error: Invalid JSON string.\n");
                    return NULL;
                }
                token->type = JSON_TYPE_OBJECT_END;
                current_depth--;
                break;
            case '[':
                if (current_depth >= MAX_JSON_NESTING_DEPTH) {
                    printf("Error: Maximum nesting depth exceeded.\n");
                    return NULL;
                }
                token->type = JSON_TYPE_ARRAY_START;
                current_depth++;
                break;
            case ']':
                if (current_depth <= 0) {
                    printf("Error: Invalid JSON string.\n");
                    return NULL;
                }
                token->type = JSON_TYPE_ARRAY_END;
                current_depth--;
                break;
            case '\"': {
                char *start = ptr + 1;
                char *end = strchr(start, '\"');
                if (end == NULL) {
                    printf("Error: Invalid JSON string.\n");
                    return NULL;
                }
                size_t len = end - start;
                token->value = malloc(len + 1);
                strncpy(token->value, start, len);
                token->value[len] = '\0';
                token->value_len = len;
                token->type = JSON_TYPE_STRING;
                ptr = end;
                break;
            }
            case 't':
            case 'f': {
                char *start = ptr;
                char *end = start + 4;
                if (strncmp(start, "true", 4) == 0) {
                    token->type = JSON_TYPE_BOOLEAN;
                    token->value = malloc(5);
                    strncpy(token->value, start, 4);
                    token->value[4] = '\0';
                    token->value_len = 4;
                } else if (strncmp(start, "false", 5) == 0) {
                    token->type = JSON_TYPE_BOOLEAN;
                    token->value = malloc(6);
                    strncpy(token->value, start, 5);
                    token->value[5] = '\0';
                    token->value_len = 5;
                } else {
                    printf("Error: Invalid JSON string.\n");
                    return NULL;
                }
                ptr = end - 1;
                break;
            }
            case 'n': {
                char *start = ptr;
                char *end = start + 4;
                if (strncmp(start, "null", 4) == 0) {
                    token->type = JSON_TYPE_NULL;
                    token->value = malloc(5);
                    strncpy(token->value, start, 4);
                    token->value[4] = '\0';
                    token->value_len = 4;
                } else {
                    printf("Error: Invalid JSON string.\n");
                    return NULL;
                }
                ptr = end - 1;
                break;
            }
        }
        if (token->type != JSON_TYPE_INVALID) {
            break;
        }
        ptr++;
    }

    if (token->type == JSON_TYPE_INVALID) {
        printf("Error: Invalid JSON string.\n");
        return NULL;
    }

    return token;
}

int main() {
    char json_string[MAX_STRING_LEN];
    printf("Enter JSON string: ");
    fgets(json_string, MAX_STRING_LEN, stdin);

    char *ptr = json_string;
    while (*ptr != '\0' && current_depth >= 0) {
        struct json_token *token = parse_json_token(ptr);
        if (token == NULL) {
            printf("Error parsing JSON string.\n");
            break;
        }
        switch (token->type) {
            case JSON_TYPE_OBJECT_START:
                printf("Object Start\n");
                break;
            case JSON_TYPE_OBJECT_END:
                printf("Object End\n");
                break;
            case JSON_TYPE_ARRAY_START:
                printf("Array Start\n");
                break;
            case JSON_TYPE_ARRAY_END:
                printf("Array End\n");
                break;
            case JSON_TYPE_STRING:
                printf("String: %s\n", token->value);
                break;
            case JSON_TYPE_NUMBER:
                printf("Number: %s\n", token->value);
                break;
            case JSON_TYPE_BOOLEAN:
                printf("Boolean: %s\n", token->value);
                break;
            case JSON_TYPE_NULL:
                printf("Null\n");
                break;
            default:
                printf("Invalid Token\n");
                break;
        }
        ptr += token->value_len + 1;
        free(token->value);
        free(token);
    }

    return 0;
}