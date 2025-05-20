#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

typedef struct Token {
  char *data;
  struct Token *next;
} Token;

Token *parse_expression(Token *head) {
  Token *new_token = malloc(sizeof(Token));
  new_token->data = strdup("(");
  new_token->next = head;
  head = new_token;

  if (head->next) {
    parse_expression(head->next);
  }

  if (head->next && head->next->next && head->next->next->data[0] == ')') {
    free(head->next);
    head->next = NULL;
  }

  return head;
}

int main() {
  Token *head = malloc(sizeof(Token));
  head->data = strdup("((())())");

  parse_expression(head);

  return 0;
}
