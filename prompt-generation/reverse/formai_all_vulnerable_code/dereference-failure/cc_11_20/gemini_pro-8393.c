//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

typedef struct json_value {
  int type; // 0 = null, 1 = string, 2 = number, 3 = array, 4 = object
  union {
    char *string;
    double number;
    struct json_value **array;
    int array_length;
    struct json_kv_pair **object;
    int object_length;
  };
} json_value;

typedef struct json_kv_pair {
  char *key;
  json_value *value;
} json_kv_pair;

json_value *json_parse(char *json_string) {
  json_value *root = malloc(sizeof(json_value));
  root->type = 0;

  char *current_char = json_string;
  while (*current_char != '\0') {
    switch (*current_char) {
      case '"':
        // Parse string
        root->type = 1;
        root->string = malloc(MAX_JSON_LENGTH);
        int string_length = 0;
        current_char++;
        while (*current_char != '"') {
          root->string[string_length++] = *current_char++;
        }
        root->string[string_length] = '\0';
        current_char++;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        // Parse number
        root->type = 2;
        char *number_string = malloc(MAX_JSON_LENGTH);
        int number_length = 0;
        while (*current_char != ',' && *current_char != '}' && *current_char != ']') {
          number_string[number_length++] = *current_char++;
        }
        number_string[number_length] = '\0';
        root->number = atof(number_string);
        free(number_string);
        break;
      case '[':
        // Parse array
        root->type = 3;
        root->array = malloc(MAX_JSON_LENGTH * sizeof(json_value *));
        root->array_length = 0;
        current_char++;
        while (*current_char != ']') {
          root->array[root->array_length++] = json_parse(current_char);
          while (*current_char != ',' && *current_char != ']') {
            current_char++;
          }
          if (*current_char == ',') {
            current_char++;
          }
        }
        current_char++;
        break;
      case '{':
        // Parse object
        root->type = 4;
        root->object = malloc(MAX_JSON_LENGTH * sizeof(json_kv_pair *));
        root->object_length = 0;
        current_char++;
        while (*current_char != '}') {
          // Parse key
          char *key = malloc(MAX_JSON_LENGTH);
          int key_length = 0;
          while (*current_char != '"') {
            key[key_length++] = *current_char++;
          }
          key[key_length] = '\0';
          current_char++;

          // Parse value
          root->object[root->object_length] = malloc(sizeof(json_kv_pair));
          root->object[root->object_length]->key = key;
          root->object[root->object_length]->value = json_parse(current_char);

          // Move to next key-value pair
          while (*current_char != ',' && *current_char != '}') {
            current_char++;
          }
          if (*current_char == ',') {
            current_char++;
          }
          root->object_length++;
        }
        current_char++;
        break;
      default:
        // Ignore whitespace and other characters
        current_char++;
        break;
    }
  }

  return root;
}

void json_print(json_value *value) {
  switch (value->type) {
    case 0:
      printf("null");
      break;
    case 1:
      printf("\"%s\"", value->string);
      break;
    case 2:
      printf("%f", value->number);
      break;
    case 3:
      printf("[");
      for (int i = 0; i < value->array_length; i++) {
        if (i > 0) {
          printf(", ");
        }
        json_print(value->array[i]);
      }
      printf("]");
      break;
    case 4:
      printf("{");
      for (int i = 0; i < value->object_length; i++) {
        if (i > 0) {
          printf(", ");
        }
        printf("\"%s\": ", value->object[i]->key);
        json_print(value->object[i]->value);
      }
      printf("}");
      break;
  }
}

int main() {
  char *json_string = "{\"name\": \"John Doe\", \"age\": 30, \"address\": {\"street\": \"Main Street\", \"city\": \"Anytown\", \"state\": \"CA\"}, \"hobbies\": [\"coding\", \"reading\", \"hiking\"]}";
  json_value *root = json_parse(json_string);
  json_print(root);
  return 0;
}