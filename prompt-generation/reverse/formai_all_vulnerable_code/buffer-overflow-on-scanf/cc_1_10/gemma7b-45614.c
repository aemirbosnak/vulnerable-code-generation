//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 16

typedef struct HexNode {
  int value;
  struct HexNode* next;
} HexNode;

HexNode* insertNode(HexNode* head, int value) {
  HexNode* newNode = malloc(sizeof(HexNode));
  newNode->value = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void printHex(HexNode* head) {
  while (head) {
    printf("%x ", head->value);
    head = head->next;
  }
  printf("\n");
}

int main() {
  HexNode* head = NULL;

  printf("Enter a hexadecimal number: ");
  char input[MAX_DIGITS];
  scanf("%s", input);

  // Convert input to uppercase
  for (int i = 0; input[i] != '\0'; i++) {
    input[i] = toupper(input[i]);
  }

  // Convert input to a linked list of hex digits
  for (int i = 0; input[i] != '\0'; i++) {
    int digit = input[i] - 'A' + 10;
    head = insertNode(head, digit);
  }

  // Print the converted hexadecimal number
  printHex(head);

  return 0;
}