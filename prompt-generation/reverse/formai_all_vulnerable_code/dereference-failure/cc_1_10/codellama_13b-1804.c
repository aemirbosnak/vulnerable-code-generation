//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
// JSON Parser in Sherlock Holmes style

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct {
  char *key;
  char *value;
} JSON_PAIR;

typedef struct {
  JSON_PAIR *pairs;
  int num_pairs;
} JSON_OBJECT;

JSON_OBJECT *parse_json(char *json) {
  JSON_OBJECT *obj = malloc(sizeof(JSON_OBJECT));
  obj->pairs = malloc(sizeof(JSON_PAIR) * 10);
  obj->num_pairs = 0;

  char *p = json;
  while (*p) {
    char *key = p;
    while (*p != '"') p++;
    *p++ = '\0';

    char *value = p;
    while (*p != '"') p++;
    *p++ = '\0';

    obj->pairs[obj->num_pairs].key = key;
    obj->pairs[obj->num_pairs].value = value;
    obj->num_pairs++;

    p++;
  }

  return obj;
}

void print_json_object(JSON_OBJECT *obj) {
  for (int i = 0; i < obj->num_pairs; i++) {
    printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
  }
}

int main() {
  char json[MAX_SIZE] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
  JSON_OBJECT *obj = parse_json(json);
  print_json_object(obj);
  free(obj);
  return 0;
}