//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
// JSON parser example program in a Ken Thompson style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *value;
} JSON_OBJECT;

typedef struct {
  char *key;
  JSON_OBJECT *value;
} JSON_ARRAY;

JSON_ARRAY *parse_json(char *str) {
  JSON_ARRAY *root = malloc(sizeof(JSON_ARRAY));
  root->key = "root";
  root->value = NULL;

  while (*str != '\0') {
    if (*str == '{') {
      JSON_OBJECT *obj = malloc(sizeof(JSON_OBJECT));
      obj->name = "obj";
      obj->value = NULL;
      root->value = obj;

      while (*str != '}') {
        str++;
        if (*str == '"') {
          str++;
          obj->name = malloc(strlen(str));
          strcpy(obj->name, str);
          str += strlen(obj->name) + 1;
        } else if (*str == ':') {
          str++;
          if (*str == '"') {
            str++;
            obj->value = malloc(strlen(str));
            strcpy(obj->value, str);
            str += strlen(obj->value) + 1;
          }
        }
      }
      str++;
    } else if (*str == ',') {
      str++;
      JSON_OBJECT *obj = malloc(sizeof(JSON_OBJECT));
      obj->name = "obj";
      obj->value = NULL;
      root->value = obj;
    }
  }

  return root;
}

int main() {
  char *str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
  JSON_ARRAY *root = parse_json(str);
  JSON_OBJECT *obj = root->value;
  while (obj != NULL) {
    printf("%s: %s\n", obj->name, obj->value);
    obj = obj->value;
  }
  return 0;
}