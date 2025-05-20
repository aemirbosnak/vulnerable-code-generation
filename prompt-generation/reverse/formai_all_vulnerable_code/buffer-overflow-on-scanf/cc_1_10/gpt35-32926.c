//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

void addToList(Node** list, int value) {
  Node* newNode = malloc(sizeof(Node));
  newNode->val = value;
  newNode->next = NULL;
  if (*list == NULL) {
    *list  = newNode;
    return;
  }
  Node* currentNode = *list;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
}

void printList(Node* list) {
  if (list == NULL) {
    printf("Empty list\n");
    return;
  }
  Node* currentNode = list;
  while (currentNode != NULL) {
    printf("%d ", currentNode->val);
    currentNode = currentNode->next;
  }
  printf("\n");
}

void simulateCircuit() {
  Node* inputs = NULL;
  Node* outputs = NULL;

  printf("Enter number of inputs: ");
  int numInputs;
  scanf("%d", &numInputs);

  for (int i = 0; i < numInputs; i++) {
    printf("Enter input value %d (0 or 1): ", i);
    int inputVal;
    scanf("%d", &inputVal);
    addToList(&inputs, inputVal);
  }

  Node* currentNode = inputs;
  while (currentNode != NULL) {
    addToList(&outputs, currentNode->val);
    currentNode = currentNode->next;
  }

  printf("Inputs: ");
  printList(inputs);
  printf("Outputs: ");
  printList(outputs);
}

int main() {
  printf("Welcome to the mind-bending C circuit simulator!\n\n");
  simulateCircuit();
  printf("\nGoodbye!\n");
  return 0;
}