//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_BUFFER_SIZE 1024

typedef struct {
    char *key;
    char *value;
} JsonObject;

JsonObject *parse_json(char *json) {
    JsonObject *obj = malloc(sizeof(JsonObject));
    obj->key = malloc(JSON_BUFFER_SIZE);
    obj->value = malloc(JSON_BUFFER_SIZE);

    char *key_start = json;
    char *value_start = json;

    int key_length = 0;
    int value_length = 0;

    while (*json != '\0') {
        if (*json == '\"') {
            if (key_length == 0) {
                key_start = json + 1;
            } else {
                key_length = json - key_start;
                obj->key = realloc(obj->key, key_length + 1);
                strncpy(obj->key, key_start, key_length);
                obj->key[key_length] = '\0';
            }
        } else if (*json == ':') {
            value_start = json + 1;
        } else if (*json == ',') {
            value_length = json - value_start;
            obj->value = realloc(obj->value, value_length + 1);
            strncpy(obj->value, value_start, value_length);
            obj->value[value_length] = '\0';

            // create a new JsonObject and add it to the list
            JsonObject *new_obj = parse_json(json + 1);
            new_obj->key = obj->key;
            new_obj->value = obj->value;
            obj = new_obj;
        }
        json++;
    }

    return obj;
}

int main() {
    char json[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JsonObject *obj = parse_json(json);
    printf("name: %s\n", obj->key);
    printf("age: %s\n", obj->value);
    printf("city: %s\n", obj->key);
    return 0;
}