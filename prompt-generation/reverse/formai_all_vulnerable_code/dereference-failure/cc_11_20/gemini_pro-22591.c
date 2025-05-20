//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JSONType;

typedef struct {
    JSONType type;
    union {
        int bool;
        double number;
        char *string;
        struct {
            int count;
            void **items;
        } array;
        struct {
            int count;
            char **keys;
            void **values;
        } object;
    } value;
} JSONValue;

JSONValue *json_parse(char *json) {
    char *end;
    JSONValue *value = malloc(sizeof(JSONValue));
    if (!value) return NULL;

    if (!json) {
        value->type = JSON_NULL;
        return value;
    }

    // Skip whitespace
    while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') json++;

    switch (*json) {
        case 'n':
            if (!strncmp(json, "null", 4)) {
                value->type = JSON_NULL;
                return value;
            }
            break;
        case 't':
            if (!strncmp(json, "true", 4)) {
                value->type = JSON_BOOL;
                value->value.bool = 1;
                return value;
            }
            break;
        case 'f':
            if (!strncmp(json, "false", 5)) {
                value->type = JSON_BOOL;
                value->value.bool = 0;
                return value;
            }
            break;
        case '"':
            value->type = JSON_STRING;
            value->value.string = malloc(strlen(json) + 1);
            if (!value->value.string) return NULL;
            strcpy(value->value.string, json + 1);
            end = strchr(value->value.string, '"');
            if (!end) return NULL;
            *end = '\0';
            return value;
        case '[':
            value->type = JSON_ARRAY;
            value->value.array.count = 0;
            value->value.array.items = NULL;
            json++;
            while (*json != ']') {
                value->value.array.count++;
                value->value.array.items = realloc(value->value.array.items, value->value.array.count * sizeof(void *));
                if (!value->value.array.items) return NULL;
                value->value.array.items[value->value.array.count - 1] = json_parse(json);
                if (!value->value.array.items[value->value.array.count - 1]) return NULL;
                while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') json++;
                if (*json == ',') json++;
            }
            return value;
        case '{':
            value->type = JSON_OBJECT;
            value->value.object.count = 0;
            value->value.object.keys = NULL;
            value->value.object.values = NULL;
            json++;
            while (*json != '}') {
                value->value.object.count++;
                value->value.object.keys = realloc(value->value.object.keys, value->value.object.count * sizeof(char *));
                if (!value->value.object.keys) return NULL;
                value->value.object.values = realloc(value->value.object.values, value->value.object.count * sizeof(void *));
                if (!value->value.object.values) return NULL;
                end = strchr(json, ':');
                if (!end) return NULL;
                *end = '\0';
                value->value.object.keys[value->value.object.count - 1] = malloc(strlen(json) + 1);
                if (!value->value.object.keys[value->value.object.count - 1]) return NULL;
                strcpy(value->value.object.keys[value->value.object.count - 1], json);
                json = end + 1;
                value->value.object.values[value->value.object.count - 1] = json_parse(json);
                if (!value->value.object.values[value->value.object.count - 1]) return NULL;
                while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') json++;
                if (*json == ',') json++;
            }
            return value;
        default:
            value->type = JSON_NUMBER;
            value->value.number = strtod(json, &end);
            if (json == end) return NULL;
            return value;
    }
}

void json_free(JSONValue *value) {
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            for (int i = 0; i < value->value.array.count; i++) {
                json_free(value->value.array.items[i]);
            }
            free(value->value.array.items);
            break;
        case JSON_OBJECT:
            for (int i = 0; i < value->value.object.count; i++) {
                free(value->value.object.keys[i]);
                json_free(value->value.object.values[i]);
            }
            free(value->value.object.keys);
            free(value->value.object.values);
            break;
        default:
            break;
    }
    free(value);
}

void json_print(JSONValue *value, int indent) {
    char *padding = malloc(indent * 2 + 1);
    if (!padding) return;
    memset(padding, ' ', indent * 2);
    padding[indent * 2] = '\0';

    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(value->value.bool ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (int i = 0; i < value->value.array.count; i++) {
                if (i > 0) printf(", ");
                printf("\n%s", padding);
                json_print(value->value.array.items[i], indent + 1);
            }
            printf("\n%s]", padding);
            break;
        case JSON_OBJECT:
            printf("{");
            for (int i = 0; i < value->value.object.count; i++) {
                if (i > 0) printf(", ");
                printf("\n%s\"%s\": ", padding, value->value.object.keys[i]);
                json_print(value->value.object.values[i], indent + 1);
            }
            printf("\n%s}", padding);
            break;
        default:
            break;
    }

    free(padding);
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"friends\": [\"Alice\", \"Bob\", \"Carol\"]}";
    JSONValue *value = json_parse(json);
    if (!value) return 1;

    json_print(value, 0);

    json_free(value);

    return 0;
}