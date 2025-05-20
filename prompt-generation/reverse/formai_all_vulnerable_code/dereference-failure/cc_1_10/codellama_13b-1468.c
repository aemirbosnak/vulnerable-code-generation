//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: creative
/// A JSON Parser Example Program in a Creative Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_STRING_SIZE 1024
#define JSON_OBJECT_SIZE 1024

typedef struct {
    char *key;
    char *value;
} JSON_Pair;

typedef struct {
    JSON_Pair *pairs;
    int num_pairs;
} JSON_Object;

JSON_Object* parse_json_object(char *json_string) {
    JSON_Object *json_obj = malloc(sizeof(JSON_Object));
    json_obj->pairs = malloc(JSON_OBJECT_SIZE * sizeof(JSON_Pair));
    json_obj->num_pairs = 0;

    char *key = NULL;
    char *value = NULL;
    char *json_str = json_string;

    while (*json_str != '\0') {
        if (*json_str == '{') {
            json_str++;
            continue;
        }
        else if (*json_str == '}') {
            json_str++;
            break;
        }
        else if (*json_str == '"') {
            key = json_str;
            while (*json_str != '"') {
                json_str++;
            }
            json_str++;
            *json_str = '\0';
        }
        else if (*json_str == ':') {
            json_str++;
            value = json_str;
            while (*json_str != '"') {
                json_str++;
            }
            json_str++;
            *json_str = '\0';
        }
        else {
            json_str++;
        }

        JSON_Pair pair = {key, value};
        json_obj->pairs[json_obj->num_pairs++] = pair;
    }

    return json_obj;
}

int main() {
    char json_string[JSON_STRING_SIZE] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    JSON_Object *json_obj = parse_json_object(json_string);

    for (int i = 0; i < json_obj->num_pairs; i++) {
        printf("%s: %s\n", json_obj->pairs[i].key, json_obj->pairs[i].value);
    }

    free(json_obj->pairs);
    free(json_obj);

    return 0;
}