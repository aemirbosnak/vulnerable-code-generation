//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define MAX_NUM_LEN 10

typedef struct {
  char key[MAX_STR_LEN];
  char value[MAX_STR_LEN];
} KeyVal;

typedef struct {
  KeyVal *keys;
  int num_keys;
} JsonObj;

// Function to print a single key-value pair
void print_keyval(KeyVal pair) {
  printf("\"%s\": \"%s\"", pair.key, pair.value);
}

// Function to print a JSON object
void print_obj(JsonObj obj) {
  printf("{ ");
  for (int i = 0; i < obj.num_keys; i++) {
    print_keyval(obj.keys[i]);
    if (i < obj.num_keys - 1) {
      printf(", ");
    }
  }
  printf(" }");
}

// Function to parse a string into a JSON object
JsonObj parse_json(char *input) {
  JsonObj obj;
  obj.num_keys = 0;

  char *token = strtok(input, "{\":,}");
  KeyVal pair;
  int i = 0;

  while (token != NULL) {
    switch (i) {
      case 0:
        strcpy(pair.key, token);
        break;
      case 1:
        strcpy(pair.value, token);
        obj.keys[obj.num_keys++] = pair;
        memset(pair.key, 0, sizeof pair.key);
        memset(pair.value, 0, sizeof pair.value);
        break;
    }

    i = (i + 1) % 2;
    token = strtok(NULL, "{\":,}");
  }

  return obj;
}

int main() {
  printf("Enter a JSON object in the following format: {\"key1\": \"value1\", \"key2\": \"value2\", ...}\n");

  char input[MAX_STR_LEN * 2 + MAX_NUM_LEN * 2 + 10];
  fgets(input, sizeof(input), stdin);
  input[strlen(input) - 1] = '\0';
  
  JsonObj obj = parse_json(input);

  printf("Parsed JSON object: ");
  print_obj(obj);
  printf("\n");

  return 0;
}