//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_value {
    enum {
        JSON_NULL,
        JSON_BOOL,
        JSON_NUMBER,
        JSON_STRING,
        JSON_ARRAY,
        JSON_OBJECT
    } type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_value **array;
        size_t array_size;
        struct json_value **object;
        size_t object_size;
    };
} json_value;

json_value *json_parse(const char *json);
void json_free(json_value *json);
void json_print(json_value *json, int indent);

int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": 25, \"children\": [\"Alice\", \"Bob\", \"Charlie\"]}";
    json_value *parsed = json_parse(json);
    json_print(parsed, 0);
    json_free(parsed);
    return 0;
}

json_value *json_parse(const char *json) {
    json_value *value = malloc(sizeof(json_value));
    if (!value) {
        return NULL;
    }
    char *start = (char *)json;
    int depth = 0;
    while (*start) {
        switch (*start) {
            case '{':
                if (depth == 0) {
                    value->type = JSON_OBJECT;
                    value->object = malloc(sizeof(json_value *));
                    value->object_size = 0;
                } else {
                    json_value *new_value = malloc(sizeof(json_value));
                    if (!new_value) {
                        return NULL;
                    }
                    new_value->type = JSON_OBJECT;
                    new_value->object = malloc(sizeof(json_value *));
                    new_value->object_size = 0;
                    value->object[value->object_size++] = new_value;
                    value = new_value;
                }
                depth++;
                start++;
                break;
            case '}':
                depth--;
                if (depth == 0) {
                    return value;
                } else {
                    value = value->object[value->object_size - 1];
                }
                start++;
                break;
            case '[':
                if (depth == 0) {
                    value->type = JSON_ARRAY;
                    value->array = malloc(sizeof(json_value *));
                    value->array_size = 0;
                } else {
                    json_value *new_value = malloc(sizeof(json_value));
                    if (!new_value) {
                        return NULL;
                    }
                    new_value->type = JSON_ARRAY;
                    new_value->array = malloc(sizeof(json_value *));
                    new_value->array_size = 0;
                    value->array[value->array_size++] = new_value;
                    value = new_value;
                }
                depth++;
                start++;
                break;
            case ']':
                depth--;
                if (depth == 0) {
                    return value;
                } else {
                    value = value->array[value->array_size - 1];
                }
                start++;
                break;
            case '"':
                {
                    start++;
                    char *end = strchr(start, '"');
                    if (!end) {
                        return NULL;
                    }
                    size_t length = end - start;
                    char *string = malloc(length + 1);
                    if (!string) {
                        return NULL;
                    }
                    strncpy(string, start, length);
                    string[length] = '\0';
                    value->type = JSON_STRING;
                    value->string = string;
                    start = end + 1;
                }
                break;
            case 't':
                if (strncmp(start, "true", 4) == 0) {
                    value->type = JSON_BOOL;
                    value->boolean = 1;
                    start += 4;
                } else {
                    return NULL;
                }
                break;
            case 'f':
                if (strncmp(start, "false", 5) == 0) {
                    value->type = JSON_BOOL;
                    value->boolean = 0;
                    start += 5;
                } else {
                    return NULL;
                }
                break;
            case 'n':
                if (strncmp(start, "null", 4) == 0) {
                    value->type = JSON_NULL;
                    start += 4;
                } else {
                    return NULL;
                }
                break;
            case ',':
                start++;
                break;
            case ':':
                start++;
                break;
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                start++;
                break;
            default:
                return NULL;
        }
    }
    return value;
}

void json_free(json_value *json) {
    switch (json->type) {
        case JSON_STRING:
            free(json->string);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < json->array_size; i++) {
                json_free(json->array[i]);
            }
            free(json->array);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < json->object_size; i++) {
                json_free(json->object[i]);
            }
            free(json->object);
            break;
        default:
            break;
    }
    free(json);
}

void json_print(json_value *json, int indent) {
    switch (json->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(json->boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", json->number);
            break;
        case JSON_STRING:
            printf("\"%s\"", json->string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (size_t i = 0; i < json->array_size; i++) {
                json_print(json->array[i], indent + 2);
                if (i < json->array_size - 1) {
                    printf(", ");
                }
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (size_t i = 0; i < json->object_size; i++) {
                json_print(json->object[i], indent + 2);
                if (i < json->object_size - 1) {
                    printf(", ");
                }
            }
            printf("}");
            break;
    }
}