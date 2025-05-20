//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryConverter {
  int decimal;
  struct BinaryConverter* next;
} BinaryConverter;

void insertAtTail(BinaryConverter** head, int decimal) {
  BinaryConverter* newNode = malloc(sizeof(BinaryConverter));
  newNode->decimal = decimal;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void convertDecimalToBinary(BinaryConverter* head) {
  int quotient = head->decimal;
  int remainder;

  while (quotient) {
    remainder = quotient % 2;
    quotient /= 2;
    insertAtTail(&head, remainder);
  }
}

int main() {
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  BinaryConverter* head = NULL;
  insertAtTail(&head, decimal);

  convertDecimalToBinary(head);

  printf("Binary representation: ");
  for (BinaryConverter* current = head; current; current = current->next) {
    printf("%d ", current->decimal);
  }

  printf("\n");

  return 0;
}