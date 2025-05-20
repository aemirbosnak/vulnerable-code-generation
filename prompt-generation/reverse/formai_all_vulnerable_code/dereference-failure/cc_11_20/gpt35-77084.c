//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024
#define MAX_TOKEN_LENGTH 64

typedef enum TokenType {
    BEGIN_OBJECT, END_OBJECT, BEGIN_ARRAY, END_ARRAY, STRING, NUMBER, BOOLEAN, NULL_TOKEN, COMMA, COLON
} TokenType;

typedef struct Token {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

typedef struct JsonNode JsonNode;
struct JsonNode {
    char key[MAX_TOKEN_LENGTH];
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
    JsonNode* nextNode;
};

Token* getToken(char* json, int* index);
JsonNode* parseJson(char* json);
void printJson(JsonNode* node);

int main() {
    char* jsonString = "{\"name\":\"John\",\"age\":30,\"car\":null,\"friends\":[\"Anna\",\"Ben\",\"Samantha\"]}";
    JsonNode* rootNode = parseJson(jsonString);
    printJson(rootNode);
    return 0;
}

Token* getToken(char* json, int* index) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = NULL_TOKEN;
    char c = json[*index];
    int pos = 0;
    while (*index < strlen(json)) {
        c = json[*index];
        (*index)++;
        if (c == '{') {
            token->type = BEGIN_OBJECT;
            break;
        }
        else if (c == '}') {
            token->type = END_OBJECT;
            break;
        }
        else if (c == '[') {
            token->type = BEGIN_ARRAY;
            break;
        }
        else if (c == ']') {
            token->type = END_ARRAY;
            break;
        }
        else if (c == ':') {
            token->type = COLON;
            break;
        }
        else if (c == ',') {
            token->type = COMMA;
            break;
        }
        else if (c == '\"') {
            token->type = STRING;
            while (json[*index] != '\"' && pos < MAX_TOKEN_LENGTH) {
                token->value[pos++] = json[*index];
                (*index)++;
            }
            break;
        }
        else if (c == 't' || c == 'f') {
            token->type = BOOLEAN;
            token->value[pos++] = c;
            while (json[*index] != '\0' && pos < MAX_TOKEN_LENGTH) {
                token->value[pos++] = json[*index];
                if (json[*index] == ',' || json[*index] == ' ' || json[*index] == '}' || json[*index] == ']') {
                    break;
                }
                (*index)++;
            }
            break;
        }
        else if (c == 'n') {
            token->type = NULL_TOKEN;
            strncpy(token->value, "null", 4);
            break;
        }
        else if ((c >= '0' && c <= '9') || c == '-') {
            token->type = NUMBER;
            token->value[pos++] = c;
            while ((json[*index] >= '0' && json[*index] <= '9') || json[*index] == '.') {
                token->value[pos++] = json[*index];
                (*index)++;
            }
            break;
        }
        else if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            continue;
        }
        else {
            printf("Invalid JSON token: %c\n", c);
            break;
        }
    }
    return token;
}

JsonNode* parseJson(char* json) {
    JsonNode* rootNode = (JsonNode*)malloc(sizeof(JsonNode));
    rootNode->type = BEGIN_OBJECT;
    rootNode->nextNode = NULL;
    int index = 0;
    Token* token = getToken(json, &index);
    int expectingKey = 1;
    JsonNode* currentNode = rootNode;
    while (token->type != NULL_TOKEN) {
        if (token->type == BEGIN_OBJECT) {
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = BEGIN_OBJECT;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = newNode;
            expectingKey = 1;
        }
        else if (token->type == END_OBJECT) {
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = END_OBJECT;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = currentNode->nextNode;
            expectingKey = 0;
        }
        else if (token->type == BEGIN_ARRAY) {
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = BEGIN_ARRAY;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = newNode;
            expectingKey = 0;
        }
        else if (token->type == END_ARRAY) {
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = END_ARRAY;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = currentNode->nextNode;
            expectingKey = 0;
        }
        else if (token->type == STRING) {
            if (expectingKey) {
                strncpy(currentNode->key, token->value, strlen(token->value) + 1);
                expectingKey = 0;
            }
            else {
                strncpy(currentNode->value, token->value, strlen(token->value) + 1);
                JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
                newNode->key[0] = '\0';
                newNode->type = STRING;
                newNode->nextNode = NULL;
                currentNode->nextNode = newNode;
                currentNode = currentNode->nextNode;
                expectingKey = 1;
            }
        }
        else if (token->type == NUMBER) {
            strncpy(currentNode->value, token->value, strlen(token->value) + 1);
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = NUMBER;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = currentNode->nextNode;
            expectingKey = 1;
        }
        else if (token->type == BOOLEAN) {
            strncpy(currentNode->value, token->value, strlen(token->value) + 1);
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = BOOLEAN;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = currentNode->nextNode;
            expectingKey = 1;
        }
        else if (token->type == NULL_TOKEN) {
            JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
            newNode->key[0] = '\0';
            newNode->type = NULL_TOKEN;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            expectingKey = 1;
        }
        else if (token->type == COMMA) {
            expectingKey = 1;
        }
        else if (token->type == COLON) {
            expectingKey = 0;
        }
        else {
            printf("Unexpected token: %s\n", token->value);
        }
        token = getToken(json, &index);
    }
    return rootNode;
}

void printJson(JsonNode* node) {
    JsonNode* currentNode = node->nextNode;
    while (currentNode != NULL) {
        switch (currentNode->type) {
            case BEGIN_OBJECT:
                printf("{\n");
                printJson(currentNode);
                printf("}\n");
                break;
            case END_OBJECT:
                return;
            case BEGIN_ARRAY:
                printf("[\n");
                printJson(currentNode);
                printf("]\n");
                break;
            case END_ARRAY:
                return;
            case STRING:
                printf("\"%s\": \"%s\", ", currentNode->key, currentNode->value);
                break;
            case NUMBER:
                printf("\"%s\": %s, ", currentNode->key, currentNode->value);
                break;
            case BOOLEAN:
                printf("\"%s\": %s, ", currentNode->key, currentNode->value);
                break;
            case NULL_TOKEN:
                printf("\"%s\": null, ", currentNode->key);
                break;
        }
        currentNode = currentNode->nextNode;
    }
}