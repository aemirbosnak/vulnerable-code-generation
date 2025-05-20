//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insert_node(Node* head, char data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    head->next = new_node;
  }

  return head;
}

int main() {
  Node* head = NULL;

  char buffer[MAX_BUFFER_SIZE];
  int buffer_size = 0;

  char input[MAX_BUFFER_SIZE];
  int input_size = 0;

  char operator;

  while (1) {
    printf("Enter an expression: ");

    // Get the input
    input[input_size++] = getchar();

    // Check if the input is an operator
    if (input[input_size - 1] == '+' || input[input_size - 1] == '-' || input[input_size - 1] == '*' || input[input_size - 1] == '/') {
      operator = input[input_size - 1];

      // Insert the operator into the linked list
      insert_node(head, operator);

      // Reset the input size
      input_size = 0;
    }

    // Check if the input is the end of the expression
    if (input[input_size - 1] == '=') {
      // Calculate the result
      int result = 0;
      Node* current = head;

      while (current) {
        switch (current->data) {
          case '+':
            result += current->next->data - '0';
            break;
          case '-':
            result -= current->next->data - '0';
            break;
          case '*':
            result *= current->next->data - '0';
            break;
          case '/':
            result /= current->next->data - '0';
            break;
        }

        current = current->next;
      }

      // Print the result
      printf("The result is: %d\n", result);

      // Reset the head of the linked list
      head = NULL;

      // Reset the input size
      input_size = 0;
    }
  }

  return 0;
}