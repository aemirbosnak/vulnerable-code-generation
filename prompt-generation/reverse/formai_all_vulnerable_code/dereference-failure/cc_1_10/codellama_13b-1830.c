//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include <ctype.h>

  #define MAX_LENGTH 1024

  typedef struct {
    char* key;
    char* value;
  } JSON_Pair;

  typedef struct {
    JSON_Pair* pairs;
    int length;
  } JSON_Object;

  JSON_Object* parse_json(char* json) {
    JSON_Object* obj = (JSON_Object*)malloc(sizeof(JSON_Object));
    obj->pairs = (JSON_Pair*)malloc(MAX_LENGTH * sizeof(JSON_Pair));
    obj->length = 0;

    while (*json != '\0') {
      // Skip whitespace
      while (isspace(*json)) {
        json++;
      }

      // Parse key
      char* key = json;
      while (*json != ':' && *json != '\0') {
        json++;
      }
      if (*json == '\0') {
        break;
      }

      // Parse value
      char* value = json + 1;
      while (*json != ',' && *json != '\0') {
        json++;
      }
      if (*json == '\0') {
        break;
      }

      // Add pair to object
      obj->pairs[obj->length].key = key;
      obj->pairs[obj->length].value = value;
      obj->length++;

      json++;
    }

    return obj;
  }

  int main() {
    char* json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JSON_Object* obj = parse_json(json);

    for (int i = 0; i < obj->length; i++) {
      printf("Key: %s, Value: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    free(obj->pairs);
    free(obj);

    return 0;
  }