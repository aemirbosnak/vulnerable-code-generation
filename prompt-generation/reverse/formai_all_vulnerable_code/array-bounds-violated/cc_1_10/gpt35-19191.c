//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_JSON_LENGTH 100
#define MAX_STACK_LENGTH 50

typedef enum {
    STRING,
    NUMBER,
    OBJECT_START,
    OBJECT_END,
    ARRAY_START,
    ARRAY_END,
    BOOLEAN,
    COLON,
    COMMA,
    END_OF_JSON
} TOKEN_TYPE;

char json[MAX_JSON_LENGTH];
int stack[MAX_STACK_LENGTH], top = -1;

void push(int value) {
    if (top >= MAX_STACK_LENGTH - 1) {
        printf("Stack overflow\n");
        exit(0);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(0);
    }
    return stack[top--];
}

char* substring(char* str, int start, int end) {
    int i, j = 0;
    char* substr = (char*)malloc((end - start + 1) * sizeof(char));
    for (i = start; i < end; i++) {
        substr[j++] = str[i];
    }
    substr[j] = '\0';
    return substr;
}

int isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

TOKEN_TYPE getTokenType(char* token) {
    if (strcmp(token, "true") == 0 || strcmp(token, "false") == 0) {
        return BOOLEAN;
    }
    if (strcmp(token, ":") == 0) {
        return COLON;
    }
    if (strcmp(token, ",") == 0) {
        return COMMA;
    }
    if (strcmp(token, "{") == 0) {
        return OBJECT_START;
    }
    if (strcmp(token, "}") == 0) {
        return OBJECT_END;
    }
    if (strcmp(token, "[") == 0) {
        return ARRAY_START;
    }
    if (strcmp(token, "]") == 0) {
        return ARRAY_END;
    }
    if (token[0] == '\"' && token[strlen(token)-1] == '\"') {
        return STRING;
    }
    if (atoi(token)) {
        return NUMBER;
    }
    return END_OF_JSON;
}

int main() {
    printf("Enter JSON:\n");
    fgets(json, MAX_JSON_LENGTH, stdin);
    json[strlen(json)-1] = '\0';

    int i, j, k, len = strlen(json), start = 0;
    TOKEN_TYPE type;
    char token[MAX_JSON_LENGTH];
    for (i = 0; i < len; i++) {
        if (isWhiteSpace(json[i])) {
            continue;
        }
        if (json[i] == '{' || json[i] == '[') {
            push(json[i]);
            continue;
        }
        if (json[i] == '}' || json[i] == ']') {
            int stackTop = pop();
            if ((json[i] == '}' && stackTop != '{') || (json[i] == ']' && stackTop != '[')) {
                printf("Mismatched brackets\n");
                exit(0);
            }
            continue;
        }
        if (json[i] == ':') {
            type = COLON;
            continue;
        }
        if (json[i] == ',') {
            type = COMMA;
            continue;
        }
        if (json[i] == '\"') {
            start = i+1;
            for (j = start; j < len; j++) {
                if (json[j] == '\"' && json[j-1] != '\\') {
                    type = STRING;
                    i = j;
                    break;
                }
            }
            if (type != STRING) {
                printf("String not terminated properly\n");
                exit(0);
            }
            strcpy(token,substring(json, start, i));
        } else {
            for (j = i; j < len; j++) {
                if (json[j] == ',' || json[j] == ']' || json[j] == '}') {
                    type = NUMBER;
                    i = j-1;
                    break;
                }
            }
            if (type != NUMBER) {
                printf("Invalid JSON\n");
                exit(0);
             }
             strcpy(token,substring(json, i, j));
        }
        printf("Token: %s Type: %d\n", token, type);
    }
    return 0;
}