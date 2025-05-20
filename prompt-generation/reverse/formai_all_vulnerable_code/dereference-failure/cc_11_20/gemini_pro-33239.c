//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

typedef struct {
  char *key;
  char *value;
} json_pair;

typedef struct {
  int count;
  json_pair *pairs;
} json_object;

json_object *json_parse(char *json_string) {
  json_object *object = malloc(sizeof(json_object));
  object->count = 0;
  object->pairs = NULL;

  char *start = json_string;
  while (*start != '\0') {
    // Skip whitespace
    while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
      start++;
    }

    // Check for the start of an object
    if (*start == '{') {
      start++;
      while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
          start++;
        }

        // Check for the end of the object
        if (*start == '}') {
          start++;
          break;
        }

        // Parse the key
        char *key = start;
        while (*start != ':' && *start != '\0') {
          start++;
        }
        *start = '\0';
        start++;

        // Parse the value
        char *value = start;
        while (*start != ',' && *start != '}' && *start != '\0') {
          start++;
        }
        *start = '\0';
        start++;

        // Add the key-value pair to the object
        object->count++;
        object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
        object->pairs[object->count - 1].key = strdup(key);
        object->pairs[object->count - 1].value = strdup(value);
      }
    }

    // Check for the start of an array
    if (*start == '[') {
      start++;
      while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
          start++;
        }

        // Check for the end of the array
        if (*start == ']') {
          start++;
          break;
        }

        // Parse the value
        char *value = start;
        while (*start != ',' && *start != ']' && *start != '\0') {
          start++;
        }
        *start = '\0';
        start++;

        // Add the value to the object
        object->count++;
        object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
        object->pairs[object->count - 1].key = NULL;
        object->pairs[object->count - 1].value = strdup(value);
      }
    }

    // Check for the start of a string
    if (*start == '"') {
      start++;
      char *value = start;
      while (*start != '"' && *start != '\0') {
        start++;
      }
      *start = '\0';
      start++;

      // Add the string to the object
      object->count++;
      object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
      object->pairs[object->count - 1].key = NULL;
      object->pairs[object->count - 1].value = strdup(value);
    }

    // Check for the start of a number
    if (*start >= '0' && *start <= '9') {
      char *value = start;
      while (*start >= '0' && *start <= '9' || *start == '.') {
        start++;
      }
      *start = '\0';
      start++;

      // Add the number to the object
      object->count++;
      object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
      object->pairs[object->count - 1].key = NULL;
      object->pairs[object->count - 1].value = strdup(value);
    }

    // Check for the start of a boolean
    if (*start == 't' || *start == 'f') {
      char *value = start;
      while (*start == 't' || *start == 'f' || *start == 'r' || *start == 'u' ||
             *start == 'e') {
        start++;
      }
      *start = '\0';
      start++;

      // Add the boolean to the object
      object->count++;
      object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
      object->pairs[object->count - 1].key = NULL;
      object->pairs[object->count - 1].value = strdup(value);
    }

    // Check for the start of a null value
    if (*start == 'n') {
      char *value = start;
      while (*start == 'n' || *start == 'u' || *start == 'l' || *start == 'l') {
        start++;
      }
      *start = '\0';
      start++;

      // Add the null value to the object
      object->count++;
      object->pairs = realloc(object->pairs, sizeof(json_pair) * object->count);
      object->pairs[object->count - 1].key = NULL;
      object->pairs[object->count - 1].value = strdup(value);
    }
  }

  return object;
}

void json_free(json_object *object) {
  for (int i = 0; i < object->count; i++) {
    free(object->pairs[i].key);
    free(object->pairs[i].value);
  }
  free(object->pairs);
  free(object);
}

int main() {
  char *json_string =
      "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";

  json_object *object = json_parse(json_string);

  for (int i = 0; i < object->count; i++) {
    printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
  }

  json_free(object);

  return 0;
}