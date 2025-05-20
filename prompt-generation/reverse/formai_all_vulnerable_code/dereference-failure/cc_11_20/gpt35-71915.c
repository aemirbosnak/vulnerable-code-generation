//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT_START,
    JSON_OBJECT_END,
    JSON_ARRAY_START,
    JSON_ARRAY_END,
    JSON_COMMA,
    JSON_COLON,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} JSON_TokenType;

typedef struct {
    JSON_TokenType type;
    char value[MAX_JSON_SIZE];
} JSON_Token;

JSON_Token* tokenizeJSON(char* json) {
    JSON_Token* tokens = (JSON_Token*) malloc(sizeof(JSON_Token) * MAX_JSON_SIZE);
    int i = 0, j = 0;
    while (json[i] != '\0') {
        if (json[i] == '\"') {
            tokens[j].type = JSON_STRING;
            int k = i + 1;
            while (json[k] != '\0' && json[k] != '\"') {
                tokens[j].value[k-i-1] = json[k];
                k++;
            }
            tokens[j].value[k-i-1] = '\0';
            i = k + 1;
            j++;
        } else if (json[i] >= '0' && json[i] <= '9') {
            tokens[j].type = JSON_NUMBER;
            int k = i;
            while (json[k] != '\0' && json[k] != ',' && json[k] != ' ' && json[k] != ']' && json[k] != '}') {
                tokens[j].value[k-i] = json[k];
                k++;
            }
            tokens[j].value[k-i] = '\0';
            i = k;
            j++;
        } else if (json[i] == '{') {
            tokens[j].type = JSON_OBJECT_START;
            tokens[j].value[0] = '{';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (json[i] == '}') {
            tokens[j].type = JSON_OBJECT_END;
            tokens[j].value[0] = '}';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (json[i] == '[') {
            tokens[j].type = JSON_ARRAY_START;
            tokens[j].value[0] = '[';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (json[i] == ']') {
            tokens[j].type = JSON_ARRAY_END;
            tokens[j].value[0] = ']';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (json[i] == ',') {
            tokens[j].type = JSON_COMMA;
            tokens[j].value[0] = ',';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (json[i] == ':') {
            tokens[j].type = JSON_COLON;
            tokens[j].value[0] = ':';
            tokens[j].value[1] = '\0';
            i++;
            j++;
        } else if (strncmp(json + i, "true", 4) == 0) {
            tokens[j].type = JSON_TRUE;
            strncpy(tokens[j].value, "true", 4);
            tokens[j].value[4] = '\0';
            i += 4;
            j++;
        } else if (strncmp(json + i, "false", 5) == 0) {
            tokens[j].type = JSON_FALSE;
            strncpy(tokens[j].value, "false", 5);
            tokens[j].value[5] = '\0';
            i += 5;
            j++;
        } else if (strncmp(json + i, "null", 4) == 0) {
            tokens[j].type = JSON_NULL;
            strncpy(tokens[j].value, "null", 4);
            tokens[j].value[4] = '\0';
            i += 4;
            j++;
        } else if (json[i] == ' ') {
            i++;
        } else {
            i++;
        }
    }
    tokens[j].type = -1;
    tokens[j].value[0] = '\0';
    return tokens;
}

int main() {
    char* json = "{\"name\" : \"John\", \"age\" : 30, \"city\" : \"New York\"}";
    JSON_Token* tokens = tokenizeJSON(json);
    for (int i = 0; tokens[i].type != -1; i++) {
        printf("%d : %s\n", tokens[i].type, tokens[i].value);
    }
    free(tokens);
    return 0;
}