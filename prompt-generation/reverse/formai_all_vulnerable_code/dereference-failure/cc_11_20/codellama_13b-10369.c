//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define JSON_PARSER_MAX_DEPTH 10

typedef struct json_value_s {
    char* key;
    char* value;
    struct json_value_s* next;
} json_value_t;

typedef struct json_object_s {
    json_value_t* values;
    struct json_object_s* next;
} json_object_t;

typedef struct json_array_s {
    json_value_t* values;
    struct json_array_s* next;
} json_array_t;

typedef struct json_parser_s {
    json_object_t* objects;
    json_array_t* arrays;
    json_value_t* values;
} json_parser_t;

int json_parse(json_parser_t* parser, char* json_string) {
    int depth = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while (json_string[i] != '\0') {
        if (depth == 0 && json_string[i] == '{') {
            json_object_t* object = malloc(sizeof(json_object_t));
            object->values = NULL;
            object->next = NULL;
            parser->objects = object;
            depth++;
        } else if (depth == 1 && json_string[i] == '"') {
            json_value_t* value = malloc(sizeof(json_value_t));
            value->key = NULL;
            value->value = NULL;
            value->next = NULL;
            json_object_t* object = parser->objects;
            while (object->next != NULL) {
                object = object->next;
            }
            object->values = value;
            depth++;
        } else if (depth == 2 && json_string[i] == ':') {
            json_value_t* value = parser->objects->values;
            value->key = malloc(sizeof(char) * (i - j + 1));
            strncpy(value->key, json_string + j, i - j);
            value->key[i - j] = '\0';
            j = i + 1;
            depth++;
        } else if (depth == 3 && json_string[i] == '"') {
            json_value_t* value = parser->objects->values;
            value->value = malloc(sizeof(char) * (i - j + 1));
            strncpy(value->value, json_string + j, i - j);
            value->value[i - j] = '\0';
            j = i + 1;
            depth++;
        } else if (depth == 4 && json_string[i] == ',') {
            depth = 1;
        } else if (depth == 4 && json_string[i] == '}') {
            depth = 0;
        } else if (depth == 0 && json_string[i] == '[') {
            json_array_t* array = malloc(sizeof(json_array_t));
            array->values = NULL;
            array->next = NULL;
            parser->arrays = array;
            depth++;
        } else if (depth == 1 && json_string[i] == '"') {
            json_value_t* value = malloc(sizeof(json_value_t));
            value->key = NULL;
            value->value = NULL;
            value->next = NULL;
            json_array_t* array = parser->arrays;
            while (array->next != NULL) {
                array = array->next;
            }
            array->values = value;
            depth++;
        } else if (depth == 2 && json_string[i] == ',') {
            depth = 1;
        } else if (depth == 2 && json_string[i] == ']') {
            depth = 0;
        }
        i++;
    }

    return 0;
}

int main() {
    char* json_string = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    json_parser_t* parser = malloc(sizeof(json_parser_t));
    parser->objects = NULL;
    parser->arrays = NULL;
    parser->values = NULL;
    json_parse(parser, json_string);

    json_object_t* object = parser->objects;
    while (object != NULL) {
        json_value_t* value = object->values;
        while (value != NULL) {
            printf("%s: %s\n", value->key, value->value);
            value = value->next;
        }
        object = object->next;
    }

    json_array_t* array = parser->arrays;
    while (array != NULL) {
        json_value_t* value = array->values;
        while (value != NULL) {
            printf("%s\n", value->value);
            value = value->next;
        }
        array = array->next;
    }

    return 0;
}