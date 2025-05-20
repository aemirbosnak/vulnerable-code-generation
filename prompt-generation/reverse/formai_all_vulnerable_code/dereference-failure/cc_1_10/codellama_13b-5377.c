//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
// JSON parser using a dynamic style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON structure
typedef struct {
  char *key;
  char *value;
  struct JSON *next;
} JSON;

// JSON parser function
JSON *parseJSON(char *json) {
  JSON *head = NULL;
  JSON *current = NULL;
  char *key = NULL;
  char *value = NULL;
  char *p = json;

  while (*p) {
    switch (*p) {
      case '{':
        current = malloc(sizeof(JSON));
        current->next = NULL;
        if (head == NULL) {
          head = current;
        } else {
          current->next = head;
          head = current;
        }
        break;
      case '"':
        if (key == NULL) {
          key = p + 1;
        } else if (value == NULL) {
          value = p + 1;
        }
        break;
      case ':':
        current->key = key;
        current->value = value;
        key = NULL;
        value = NULL;
        break;
      case ',':
        current->key = key;
        current->value = value;
        key = NULL;
        value = NULL;
        break;
      case '}':
        current->key = key;
        current->value = value;
        key = NULL;
        value = NULL;
        current = current->next;
        break;
    }
    p++;
  }

  return head;
}

// Example usage
int main() {
  char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
  JSON *head = parseJSON(json);

  while (head != NULL) {
    printf("%s: %s\n", head->key, head->value);
    head = head->next;
  }

  return 0;
}