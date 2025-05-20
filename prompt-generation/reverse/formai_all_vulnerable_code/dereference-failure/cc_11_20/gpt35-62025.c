//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_DEPTH 10
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type_t;

typedef struct json_token_t {
    json_type_t type;
    char *key;
    char *value;
    struct json_token_t *children;
} json_token_t;

json_token_t *parse_json(char *json_string, int json_level);
void print_json(json_token_t *root, int level);

int main() {
  char *json_string = "{ \"name\": \"John Smith\", \"age\": 30, \"isMarried\": true, \"hobbies\": [\"reading\", \"writing\", \"coding\"] }";
  json_token_t *root = parse_json(json_string, 0);
  print_json(root, 0);
  free(root);
  return 0;
}

json_token_t *parse_json(char *json_string, int json_level) {
  json_token_t *root = malloc(sizeof(json_token_t));
  root->key = NULL;
  root->value = NULL;
  root->children = NULL;
  char *json_start = strchr(json_string, '{');
  char *json_end = strrchr(json_string, '}');
  char *key_start = json_start + 1;
  while (key_start < json_end) {
      json_token_t *token = malloc(sizeof(json_token_t));
      token->children = NULL;
      char *key_end = strchr(key_start, ':');
      if (key_end == NULL) {
          printf("Error: Invalid JSON syntax.\n");
          free(root);
          free(token);
          return NULL;
      }
      char *value_start = key_end + 1;
      char *comma = strchr(value_start, ',');
      char *value_end;
      if (comma == NULL) {
          value_end = json_end - 1;
      } else {
          value_end = comma - 1;
      }
      int key_length = key_end - key_start;
      int value_length = value_end - value_start + 1;
      char *key = malloc(sizeof(char) * (key_length + 1));
      char *value = malloc(sizeof(char) * (value_length + 1));
      strncpy(key, key_start, key_length);
      strncpy(value, value_start, value_length);
      key[key_length] = '\0';
      value[value_length] = '\0';
      if (*key == '\"' && *(key + key_length - 1) == '\"') {
          key++;
          key_length -= 2;
          *(key + key_length) = '\0';
      }
      if (*value == '\"' && *(value + value_length - 1) == '\"') {
          value++;
          value_length -= 2;
          *(value + value_length) = '\0';
          token->type = JSON_STRING;
      } else if (!strcmp(value, "true")) {
          token->type = JSON_TRUE;
      } else if (!strcmp(value, "false")) {
          token->type = JSON_FALSE;
      } else if (!strcmp(value, "null")) {
          token->type = JSON_NULL;
      } else if (*value >= '0' && *value <= '9') {
          token->type = JSON_NUMBER;
      } else if (*value == '{') {
          token->type = JSON_OBJECT;
          char *child_start = value;
          int child_level = json_level + 1;
          token->children = parse_json(child_start, child_level);
      } else if (*value == '[') {
          token->type = JSON_ARRAY;
          char *child_start = value;
          char *child_end = strrchr(value, ']');
          int child_level = json_level + 1;
          token->children = parse_json(child_start, child_level);
          while (*child_end != ',') {
              child_end--;
          }
          token->value = malloc(sizeof(char) * (child_end - child_start));
          strncpy(token->value, child_start, child_end - child_start);
      }
      token->key = malloc(sizeof(char) * (strlen(key) + 1));
      token->value = malloc(sizeof(char) * (strlen(value) + 1));
      strcpy(token->key, key);
      strcpy(token->value, value);
      free(key);
      free(value);
      if (root->children == NULL) {
          root->children = token;
      } else {
          json_token_t *node = root->children;
          while (node->children != NULL) {
              node = node->children;
          }
          node->children = token;
      }
      key_start = comma + 1;
  }
  return root;
}

void print_json(json_token_t *root, int level) {
  if (root->type == JSON_OBJECT) {
      printf("{\n");
      json_token_t *node = root->children;
      while (node != NULL) {
          print_json(node, level+1);
          node = node->children;
          if (node != NULL) {
              printf(",\n");
          }
      }
      printf("\n");
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("}");
  } else if (root->type == JSON_STRING) {
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("\"%s\": \"%s\"", root->key, root->value);
  } else if (root->type == JSON_NUMBER) {
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("\"%s\": %s", root->key, root->value);
  } else if (root->type == JSON_TRUE) {
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("\"%s\": true", root->key);
  } else if (root->type == JSON_FALSE) {
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("\"%s\": false", root->key);
  } else if (root->type == JSON_NULL) {
      for (int i = 0; i < level; i++) {
          printf("  ");
      }
      printf("\"%s\": null", root->key);
  } else if (root->type == JSON_ARRAY) {
      printf("[");
      json_token_t *node = root->children;
      while (node != NULL) {
          print_json(node, level+1);
          node = node->children;
          if (node != NULL) {
              printf(", ");
          }
      }
      printf("]");
  }
}