//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define JSON_PARSER_MAX_DEPTH 100
#define JSON_PARSER_MAX_LENGTH 10000

typedef struct {
    char *key;
    char *value;
} json_pair_t;

typedef struct {
    json_pair_t *pairs;
    int num_pairs;
} json_object_t;

typedef struct {
    json_object_t *objects;
    int num_objects;
} json_array_t;

typedef struct {
    json_array_t *arrays;
    int num_arrays;
} json_document_t;

void json_parser_init(json_document_t *doc) {
    doc->num_arrays = 0;
    doc->arrays = NULL;
}

void json_parser_destroy(json_document_t *doc) {
    for (int i = 0; i < doc->num_arrays; i++) {
        json_array_t *array = &doc->arrays[i];
        for (int j = 0; j < array->num_objects; j++) {
            json_object_t *obj = &array->objects[j];
            for (int k = 0; k < obj->num_pairs; k++) {
                json_pair_t *pair = &obj->pairs[k];
                free(pair->key);
                free(pair->value);
            }
            free(obj->pairs);
        }
        free(array->objects);
    }
    free(doc->arrays);
}

int json_parser_parse(json_document_t *doc, char *json_str) {
    int i = 0;
    while (json_str[i] != '\0') {
        if (json_str[i] == '{' || json_str[i] == '[') {
            json_array_t *array = malloc(sizeof(json_array_t));
            array->num_objects = 0;
            array->objects = NULL;
            doc->arrays[doc->num_arrays++] = *array;
        } else if (json_str[i] == '}' || json_str[i] == ']') {
            json_array_t *array = &doc->arrays[doc->num_arrays - 1];
            for (int j = 0; j < array->num_objects; j++) {
                json_object_t *obj = &array->objects[j];
                for (int k = 0; k < obj->num_pairs; k++) {
                    json_pair_t *pair = &obj->pairs[k];
                    free(pair->key);
                    free(pair->value);
                }
                free(obj->pairs);
            }
            free(array->objects);
            doc->num_arrays--;
        } else if (json_str[i] == ':') {
            json_array_t *array = &doc->arrays[doc->num_arrays - 1];
            json_object_t *obj = &array->objects[array->num_objects - 1];
            obj->num_pairs++;
            obj->pairs = realloc(obj->pairs, sizeof(json_pair_t) * obj->num_pairs);
            json_pair_t *pair = &obj->pairs[obj->num_pairs - 1];
            pair->key = NULL;
            pair->value = NULL;
        } else if (json_str[i] == ',') {
            json_array_t *array = &doc->arrays[doc->num_arrays - 1];
            array->num_objects++;
            array->objects = realloc(array->objects, sizeof(json_object_t) * array->num_objects);
            json_object_t *obj = &array->objects[array->num_objects - 1];
            obj->num_pairs = 0;
            obj->pairs = NULL;
        } else if (json_str[i] == '"') {
            json_array_t *array = &doc->arrays[doc->num_arrays - 1];
            json_object_t *obj = &array->objects[array->num_objects - 1];
            json_pair_t *pair = &obj->pairs[obj->num_pairs - 1];
            if (pair->key == NULL) {
                pair->key = malloc(sizeof(char) * (i - 1));
                strncpy(pair->key, json_str, i - 1);
            } else {
                pair->value = malloc(sizeof(char) * (i - 1));
                strncpy(pair->value, json_str, i - 1);
            }
        }
        i++;
    }
    return 0;
}

int main() {
    json_document_t doc;
    json_parser_init(&doc);
    char *json_str = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
    json_parser_parse(&doc, json_str);
    json_parser_destroy(&doc);
    return 0;
}