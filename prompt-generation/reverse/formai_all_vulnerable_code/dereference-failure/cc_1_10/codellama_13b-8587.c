//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
/*
 * Building a JSON Parser example program in a mathematical style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON data structure
typedef struct {
    char *key;
    char *value;
} json_object_t;

// JSON array structure
typedef struct {
    json_object_t *objects;
    int num_objects;
} json_array_t;

// JSON parser state machine
typedef enum {
    START,
    IN_ARRAY,
    IN_OBJECT,
    IN_KEY,
    IN_VALUE
} json_parser_state_t;

// JSON parser function
json_array_t* parse_json(char *json) {
    json_parser_state_t state = START;
    json_array_t *array = malloc(sizeof(json_array_t));
    array->num_objects = 0;
    array->objects = NULL;

    while (*json != '\0') {
        switch (state) {
            case START:
                if (*json == '[') {
                    state = IN_ARRAY;
                } else {
                    state = IN_OBJECT;
                }
                break;
            case IN_ARRAY:
                if (*json == '[') {
                    array->num_objects++;
                    array->objects = realloc(array->objects, sizeof(json_object_t) * array->num_objects);
                    array->objects[array->num_objects - 1].key = NULL;
                    array->objects[array->num_objects - 1].value = NULL;
                } else if (*json == ']') {
                    state = START;
                } else {
                    state = IN_KEY;
                }
                break;
            case IN_OBJECT:
                if (*json == '{') {
                    array->num_objects++;
                    array->objects = realloc(array->objects, sizeof(json_object_t) * array->num_objects);
                    array->objects[array->num_objects - 1].key = NULL;
                    array->objects[array->num_objects - 1].value = NULL;
                } else if (*json == '}') {
                    state = START;
                } else {
                    state = IN_KEY;
                }
                break;
            case IN_KEY:
                if (*json == '"') {
                    state = IN_VALUE;
                } else {
                    array->objects[array->num_objects - 1].key = realloc(array->objects[array->num_objects - 1].key, sizeof(char) * (strlen(array->objects[array->num_objects - 1].key) + 1));
                    array->objects[array->num_objects - 1].key[strlen(array->objects[array->num_objects - 1].key) - 1] = *json;
                }
                break;
            case IN_VALUE:
                if (*json == '"') {
                    state = IN_KEY;
                } else {
                    array->objects[array->num_objects - 1].value = realloc(array->objects[array->num_objects - 1].value, sizeof(char) * (strlen(array->objects[array->num_objects - 1].value) + 1));
                    array->objects[array->num_objects - 1].value[strlen(array->objects[array->num_objects - 1].value) - 1] = *json;
                }
                break;
        }
        json++;
    }

    return array;
}

int main() {
    char *json = "[{\"key\": \"value\"}, {\"key2\": \"value2\"}]";
    json_array_t *array = parse_json(json);
    for (int i = 0; i < array->num_objects; i++) {
        printf("key: %s, value: %s\n", array->objects[i].key, array->objects[i].value);
    }
    return 0;
}