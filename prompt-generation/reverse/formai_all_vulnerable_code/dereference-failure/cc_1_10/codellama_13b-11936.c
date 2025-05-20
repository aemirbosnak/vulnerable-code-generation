//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  char* key;
  char* value;
} JSON_PAIR;

typedef struct {
  JSON_PAIR** pairs;
  int num_pairs;
} JSON_OBJECT;

typedef struct {
  JSON_OBJECT** objects;
  int num_objects;
} JSON_ARRAY;

typedef struct {
  JSON_ARRAY* array;
  JSON_OBJECT* object;
} JSON_VALUE;

JSON_VALUE* parse_json(char* json) {
  JSON_VALUE* value = malloc(sizeof(JSON_VALUE));
  value->array = NULL;
  value->object = NULL;

  if (json[0] == '[') {
    value->array = malloc(sizeof(JSON_ARRAY));
    value->array->objects = NULL;
    value->array->num_objects = 0;

    int i = 1;
    while (json[i] != ']') {
      JSON_OBJECT* object = malloc(sizeof(JSON_OBJECT));
      object->pairs = NULL;
      object->num_pairs = 0;

      while (json[i] != ',' && json[i] != ']') {
        JSON_PAIR* pair = malloc(sizeof(JSON_PAIR));
        pair->key = malloc(sizeof(char) * 10);
        pair->value = malloc(sizeof(char) * 10);
        sscanf(json + i, "\"%[^\"]\":\"%[^\"]\"", pair->key, pair->value);
        i += strlen(pair->key) + strlen(pair->value) + 2;

        object->pairs = realloc(object->pairs, sizeof(JSON_PAIR*) * (object->num_pairs + 1));
        object->pairs[object->num_pairs++] = pair;
      }

      value->array->objects = realloc(value->array->objects, sizeof(JSON_OBJECT*) * (value->array->num_objects + 1));
      value->array->objects[value->array->num_objects++] = object;

      if (json[i] == ',') {
        i++;
      }
    }
  } else if (json[0] == '{') {
    value->object = malloc(sizeof(JSON_OBJECT));
    value->object->pairs = NULL;
    value->object->num_pairs = 0;

    int i = 1;
    while (json[i] != '}') {
      JSON_PAIR* pair = malloc(sizeof(JSON_PAIR));
      pair->key = malloc(sizeof(char) * 10);
      pair->value = malloc(sizeof(char) * 10);
      sscanf(json + i, "\"%[^\"]\":\"%[^\"]\"", pair->key, pair->value);
      i += strlen(pair->key) + strlen(pair->value) + 2;

      value->object->pairs = realloc(value->object->pairs, sizeof(JSON_PAIR*) * (value->object->num_pairs + 1));
      value->object->pairs[value->object->num_pairs++] = pair;

      if (json[i] == ',') {
        i++;
      }
    }
  } else {
    // invalid JSON
    free(value);
    return NULL;
  }

  return value;
}

void print_json_value(JSON_VALUE* value) {
  if (value->array != NULL) {
    printf("[");
    for (int i = 0; i < value->array->num_objects; i++) {
      JSON_OBJECT* object = value->array->objects[i];
      printf("{");
      for (int j = 0; j < object->num_pairs; j++) {
        JSON_PAIR* pair = object->pairs[j];
        printf("\"%s\":\"%s\"", pair->key, pair->value);
        if (j < object->num_pairs - 1) {
          printf(",");
        }
      }
      printf("}");
      if (i < value->array->num_objects - 1) {
        printf(",");
      }
    }
    printf("]");
  } else if (value->object != NULL) {
    printf("{");
    for (int i = 0; i < value->object->num_pairs; i++) {
      JSON_PAIR* pair = value->object->pairs[i];
      printf("\"%s\":\"%s\"", pair->key, pair->value);
      if (i < value->object->num_pairs - 1) {
        printf(",");
      }
    }
    printf("}");
  }
}

int main() {
  char* json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
  JSON_VALUE* value = parse_json(json);
  print_json_value(value);
  return 0;
}