//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON parser states
#define START 0
#define KEY 1
#define VALUE 2
#define ARRAY 3
#define OBJECT 4
#define DONE 5

// Define the JSON token types
#define TOKEN_NULL 0
#define TOKEN_TRUE 1
#define TOKEN_FALSE 2
#define TOKEN_NUMBER 3
#define TOKEN_STRING 4
#define TOKEN_ARRAY_START 5
#define TOKEN_ARRAY_END 6
#define TOKEN_OBJECT_START 7
#define TOKEN_OBJECT_END 8
#define TOKEN_COMMA 9
#define TOKEN_COLON 10

// Define the JSON parser structure
typedef struct {
  char *input;
  int length;
  int pos;
  int state;
  char *key;
  char *value;
  int array_depth;
  int object_depth;
} JSONParser;

// Initialize the JSON parser
void JSONParser_Init(JSONParser *parser, char *input) {
  parser->input = input;
  parser->length = strlen(input);
  parser->pos = 0;
  parser->state = START;
  parser->key = NULL;
  parser->value = NULL;
  parser->array_depth = 0;
  parser->object_depth = 0;
}

// Get the next token from the JSON parser
int JSONParser_Next(JSONParser *parser) {
  char c;
  int token = TOKEN_NULL;

  // Skip whitespace
  while (parser->pos < parser->length && (c = parser->input[parser->pos]) && (c == ' ' || c == '\n' || c == '\r' || c == '\t')) {
    parser->pos++;
  }

  // Check for the end of the input
  if (parser->pos >= parser->length) {
    return TOKEN_NULL;
  }

  // Get the next character
  c = parser->input[parser->pos];

  // Determine the token type
  switch (c) {
    case '{':
      parser->state = OBJECT;
      parser->object_depth++;
      token = TOKEN_OBJECT_START;
      break;
    case '}':
      parser->state = DONE;
      parser->object_depth--;
      token = TOKEN_OBJECT_END;
      break;
    case '[':
      parser->state = ARRAY;
      parser->array_depth++;
      token = TOKEN_ARRAY_START;
      break;
    case ']':
      parser->state = DONE;
      parser->array_depth--;
      token = TOKEN_ARRAY_END;
      break;
    case ',':
      token = TOKEN_COMMA;
      break;
    case ':':
      token = TOKEN_COLON;
      break;
    case '"':
      parser->state = VALUE;
      parser->value = &parser->input[parser->pos + 1];
      // Skip past the opening quote
      parser->pos++;
      while (parser->pos < parser->length && (c = parser->input[parser->pos]) && c != '"') {
        parser->pos++;
      }
      // Skip past the closing quote
      parser->pos++;
      token = TOKEN_STRING;
      break;
    case 't':
      if (strncmp(&parser->input[parser->pos], "true", 4) == 0) {
        parser->pos += 4;
        token = TOKEN_TRUE;
      }
      break;
    case 'f':
      if (strncmp(&parser->input[parser->pos], "false", 5) == 0) {
        parser->pos += 5;
        token = TOKEN_FALSE;
      }
      break;
    case 'n':
      if (strncmp(&parser->input[parser->pos], "null", 4) == 0) {
        parser->pos += 4;
        token = TOKEN_NULL;
      }
      break;
    default:
      if (isdigit(c) || c == '-') {
        parser->state = VALUE;
        parser->value = &parser->input[parser->pos];
        while (parser->pos < parser->length && (c = parser->input[parser->pos]) && (isdigit(c) || c == '.' || c == 'e' || c == 'E')) {
          parser->pos++;
        }
        token = TOKEN_NUMBER;
      }
      break;
  }

  // Move to the next token
  parser->pos++;

  return token;
}

// Parse the JSON input
void JSONParser_Parse(JSONParser *parser) {
  int token;

  // Loop until the end of the input
  while ((token = JSONParser_Next(parser)) != TOKEN_NULL) {
    // Process the token
    switch (token) {
      case TOKEN_OBJECT_START:
        printf("{");
        break;
      case TOKEN_OBJECT_END:
        printf("}");
        break;
      case TOKEN_ARRAY_START:
        printf("[");
        break;
      case TOKEN_ARRAY_END:
        printf("]");
        break;
      case TOKEN_COMMA:
        printf(",");
        break;
      case TOKEN_COLON:
        printf(":");
        break;
      case TOKEN_STRING:
        printf("\"%s\"", parser->value);
        break;
      case TOKEN_NUMBER:
        printf("%s", parser->value);
        break;
      case TOKEN_TRUE:
        printf("true");
        break;
      case TOKEN_FALSE:
        printf("false");
        break;
      case TOKEN_NULL:
        printf("null");
        break;
    }
  }

  // Print a newline character
  printf("\n");
}

// Main function
int main() {
  // Create a JSON parser
  JSONParser parser;

  // Parse the JSON input
  JSONParser_Parse(&parser);

  return 0;
}