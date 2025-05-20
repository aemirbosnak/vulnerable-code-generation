//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECTS 100
#define MAX_JSON_OBJECT_SIZE 1000

enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL,
    JSON_OBJECT_BEGIN,
    JSON_OBJECT_END,
    JSON_ARRAY_BEGIN,
    JSON_ARRAY_END,
    JSON_COLON,
    JSON_COMMA
};

typedef struct {
    int type;
    union {
        char string[MAX_JSON_OBJECT_SIZE];
        double number;
        int boolean;
    } value;
} JSON_Object;

JSON_Object json_objects[MAX_JSON_OBJECTS];
int json_objects_len = 0;
char* json_data = NULL;

void parse_json() {
    char* p = json_data;
    int stack[MAX_JSON_OBJECTS] = {0};
    int stack_pos = -1;
    char key[MAX_JSON_OBJECT_SIZE] = {0};
    int key_len = 0;
    int inside_quotes = 0;
    int expecting_colon = 0;
    while (*p != '\0') {
        if (*p == '{' && !inside_quotes) {
            stack[++stack_pos] = JSON_OBJECT_BEGIN;
            json_objects[json_objects_len++] = (JSON_Object) { JSON_OBJECT_BEGIN };
        } else if (*p == '}' && !inside_quotes) {
            stack_pos--;
            json_objects[json_objects_len++] = (JSON_Object) { JSON_OBJECT_END };
        } else if (*p == '[' && !inside_quotes) {
            stack[++stack_pos] = JSON_ARRAY_BEGIN;
            json_objects[json_objects_len++] = (JSON_Object) { JSON_ARRAY_BEGIN };
        } else if (*p == ']' && !inside_quotes) {
            stack_pos--;
            json_objects[json_objects_len++] = (JSON_Object) { JSON_ARRAY_END };
        } else if (*p == '"' && *(p-1) != '\\') {
            inside_quotes = !inside_quotes;
            if (!inside_quotes) {
                if (expecting_colon) {
                    json_objects[json_objects_len++] = (JSON_Object) { JSON_STRING, .value.string = key };
                    expecting_colon = 0;
                    memset(key, 0, key_len);
                    key_len = 0;
                } else {
                    json_objects[json_objects_len++] = (JSON_Object) { JSON_STRING, .value.string = json_data };
                    json_data = p + 1;
                    *p = '\0';
                }
            } else {
                if (stack[stack_pos] == JSON_OBJECT_BEGIN) {
                    expecting_colon = 1;
                }
            }
        } else if (*p == ':' && !inside_quotes) {
            json_objects[json_objects_len++] = (JSON_Object) { JSON_COLON };
        } else if (*p == ',' && !inside_quotes) {
            json_objects[json_objects_len++] = (JSON_Object) { JSON_COMMA };
        }
        p++;
    }
}

int main() {
    json_data = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\", \"married\": false, \"pets\": [\"dog\", \"cat\"]}";
    parse_json();
    for (int i = 0; i < json_objects_len; i++) {
        switch (json_objects[i].type) {
            case JSON_OBJECT_BEGIN:
            case JSON_ARRAY_BEGIN:
                printf("%s\n", json_objects[i].type == JSON_OBJECT_BEGIN ? "OBJECT BEGIN" : "ARRAY BEGIN");
                break;
            case JSON_OBJECT_END:
            case JSON_ARRAY_END:
                printf("%s\n", json_objects[i].type == JSON_OBJECT_END ? "OBJECT END" : "ARRAY END");
                break;
            case JSON_STRING:
                printf("STRING %s\n", json_objects[i].value.string);
                break;
            case JSON_NUMBER:
                printf("NUMBER %f\n", json_objects[i].value.number);
                break;
            case JSON_BOOLEAN:
                printf("BOOLEAN %s\n", json_objects[i].value.boolean ? "true" : "false");
                break;
            case JSON_NULL:
                printf("NULL\n");
                break;
            case JSON_COLON:
                printf("COLON\n");
                break;
            case JSON_COMMA:
                printf("COMMA\n");
                break;
        }
    }
    return 0;
}