//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Parser {
  Node* head;
  int state;
  char input;
  struct Parser* next;
} Parser;

void parse_expression(Parser* parser) {
  switch (parser->state) {
    case 0:
      if (parser->input == '(') {
        parser->state = 1;
      } else if (parser->input == ')') {
        parser->state = 3;
      } else if (parser->input == '+') {
        parser->state = 2;
      } else {
        printf("Error: invalid input\n");
      }
      break;
    case 1:
      if (parser->input == ')') {
        parser->state = 3;
      } else if (parser->input == '+') {
        parser->state = 2;
      } else {
        printf("Error: invalid input\n");
      }
      break;
    case 2:
      if (parser->input == ')') {
        parser->state = 3;
      } else if (parser->input == '+') {
        parser->state = 2;
      } else {
        printf("Error: invalid input\n");
      }
      break;
    case 3:
      printf("Expression parsed: %c\n", parser->head->data);
      break;
  }
}

int main() {
  Parser* parser = malloc(sizeof(Parser));
  parser->head = NULL;
  parser->state = 0;
  parser->input = '\0';

  printf("Enter an expression: ");
  scanf("%c", &parser->input);

  parse_expression(parser);

  return 0;
}