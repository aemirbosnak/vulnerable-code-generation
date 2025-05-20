//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOL,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_value **array;
        size_t array_size;
        struct json_value **object;
        size_t object_size;
    } value;
} json_value;

json_value *json_parse(const char *json);
void json_free(json_value *value);

void json_print(const json_value *value, int indent) {
    switch (value->type) {
    case JSON_TYPE_NULL:
        printf("null");
        break;
    case JSON_TYPE_BOOL:
        printf(value->value.boolean ? "true" : "false");
        break;
    case JSON_TYPE_NUMBER:
        printf("%f", value->value.number);
        break;
    case JSON_TYPE_STRING:
        printf("\"%s\"", value->value.string);
        break;
    case JSON_TYPE_ARRAY:
        printf("[");
        for (size_t i = 0; i < value->value.array_size; i++) {
            if (i > 0) printf(", ");
            json_print(value->value.array[i], indent + 1);
        }
        printf("]");
        break;
    case JSON_TYPE_OBJECT:
        printf("{");
        for (size_t i = 0; i < value->value.object_size; i++) {
            if (i > 0) printf(", ");
            printf("\"%s\": ", value->value.object[i]->value.string);
            json_print(value->value.object[i]->value.object, indent + 1);
        }
        printf("}");
        break;
    }
}

int main() {
    const char *json_string = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
    json_value *json = json_parse(json_string);
    json_print(json, 0);
    printf("\n");
    json_free(json);
    return 0;
}

json_value *json_parse(const char *json) {
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_TYPE_NULL;
    
    char *s = (char *)json;
    while (*s != '\0') {
        switch (*s) {
        case ' ':
        case '\n':
        case '\r':
        case '\t':
            s++;
            break;
        case '{':
            value->type = JSON_TYPE_OBJECT;
            value->value.object_size = 0;
            s++;
            while (*s != '}') {
                while (*s != '\0' && *s != '"') s++;
                if (*s == '\0') break;
                s++;
                char *key = s;
                while (*s != '"') s++;
                *s++ = '\0';
                while (*s != ':') s++;
                s++;
                value->value.object = realloc(value->value.object, sizeof(json_value *) * (value->value.object_size + 1));
                value->value.object[value->value.object_size++] = json_parse(s);
            }
            s++;
            break;
        case '[':
            value->type = JSON_TYPE_ARRAY;
            value->value.array_size = 0;
            s++;
            while (*s != ']') {
                value->value.array = realloc(value->value.array, sizeof(json_value *) * (value->value.array_size + 1));
                value->value.array[value->value.array_size++] = json_parse(s);
                while (*s != ',' && *s != ']') s++;
                if (*s == ',') s++;
            }
            s++;
            break;
        case '"':
            value->type = JSON_TYPE_STRING;
            s++;
            char *str = s;
            while (*s != '"') s++;
            *s++ = '\0';
            value->value.string = strdup(str);
            break;
        case 't':
            value->type = JSON_TYPE_BOOL;
            value->value.boolean = 1;
            s += 4;
            break;
        case 'f':
            value->type = JSON_TYPE_BOOL;
            value->value.boolean = 0;
            s += 5;
            break;
        case 'n':
            value->type = JSON_TYPE_NULL;
            s += 4;
            break;
        default:
            value->type = JSON_TYPE_NUMBER;
            char *num = s;
            while (*s != ',' && *s != '}' && *s != ']' && *s != '\0') s++;
            *s = '\0';
            value->value.number = atof(num);
            break;
        }
    }
    
    return value;
}

void json_free(json_value *value) {
    switch (value->type) {
    case JSON_TYPE_STRING:
        free(value->value.string);
        break;
    case JSON_TYPE_ARRAY:
        for (size_t i = 0; i < value->value.array_size; i++) {
            json_free(value->value.array[i]);
        }
        free(value->value.array);
        break;
    case JSON_TYPE_OBJECT:
        for (size_t i = 0; i < value->value.object_size; i++) {
            json_free(value->value.object[i]);
        }
        free(value->value.object);
        break;
    }
    free(value);
}