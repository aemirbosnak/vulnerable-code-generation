//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
// Building a JSON Parser
// ------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} json_pair_t;

typedef struct {
  json_pair_t **pairs;
  size_t size;
} json_object_t;

typedef struct {
  char *value;
  json_object_t *object;
} json_value_t;

json_object_t *parse_json(char *str) {
  json_object_t *obj = malloc(sizeof(json_object_t));
  obj->pairs = malloc(sizeof(json_pair_t *) * 10);
  obj->size = 0;

  char *key = strtok(str, ":");
  while (key != NULL) {
    json_pair_t *pair = malloc(sizeof(json_pair_t));
    pair->key = key;
    pair->value = strtok(NULL, ",");
    obj->pairs[obj->size++] = pair;
    key = strtok(NULL, ":");
  }

  return obj;
}

void print_json(json_object_t *obj) {
  for (size_t i = 0; i < obj->size; i++) {
    printf("Key: %s, Value: %s\n", obj->pairs[i]->key, obj->pairs[i]->value);
  }
}

int main(void) {
  char *str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
  json_object_t *obj = parse_json(str);
  print_json(obj);
  return 0;
}