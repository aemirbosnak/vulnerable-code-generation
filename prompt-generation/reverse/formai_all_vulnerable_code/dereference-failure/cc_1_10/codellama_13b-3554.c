//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>

  #define BUFFER_SIZE 1024

  typedef struct {
    char *key;
    char *value;
  } JSON_OBJECT;

  typedef struct {
    JSON_OBJECT *objects;
    int num_objects;
  } JSON_ARRAY;

  JSON_ARRAY *parse_json(char *input) {
    JSON_ARRAY *array = malloc(sizeof(JSON_ARRAY));
    array->objects = malloc(BUFFER_SIZE * sizeof(JSON_OBJECT));
    array->num_objects = 0;

    char *ptr = input;
    while (*ptr != '\0') {
      if (*ptr == '{') {
        JSON_OBJECT *object = &array->objects[array->num_objects++];
        object->key = NULL;
        object->value = NULL;

        ptr++;
        while (*ptr != '\0' && *ptr != '}') {
          if (*ptr == '"') {
            ptr++;
            char *key = ptr;
            while (*ptr != '\0' && *ptr != '"') ptr++;
            *ptr = '\0';
            object->key = key;

            ptr++;
            if (*ptr != ':') {
              fprintf(stderr, "Error: expected ':' after key\n");
              return NULL;
            }
            ptr++;

            char *value = ptr;
            while (*ptr != '\0' && *ptr != '"') ptr++;
            *ptr = '\0';
            object->value = value;
          } else if (*ptr == ',') {
            ptr++;
          } else {
            fprintf(stderr, "Error: expected ',' or '}'\n");
            return NULL;
          }
        }
      } else if (*ptr == '}') {
        ptr++;
      } else {
        fprintf(stderr, "Error: expected '{' or '}'\n");
        return NULL;
      }
    }

    return array;
  }

  void print_json_array(JSON_ARRAY *array) {
    for (int i = 0; i < array->num_objects; i++) {
      JSON_OBJECT *object = &array->objects[i];
      printf("{\"%s\":\"%s\"}", object->key, object->value);
      if (i != array->num_objects - 1) {
        printf(",");
      }
    }
  }

  int main() {
    char *input = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
    JSON_ARRAY *array = parse_json(input);
    if (array == NULL) {
      fprintf(stderr, "Error: failed to parse JSON\n");
      return 1;
    }

    print_json_array(array);

    return 0;
  }