//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct node {
  char data;
  struct node *next;
} node_t;

typedef struct stack {
  node_t *top;
  int size;
} stack_t;

// Create a new stack
stack_t *stack_new() {
  stack_t *stack = malloc(sizeof(stack_t));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

// Push an element onto the stack
void stack_push(stack_t *stack, char data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

// Pop an element from the stack
char stack_pop(stack_t *stack) {
  if (stack->size == 0) {
    return '\0';
  }
  node_t *temp = stack->top;
  char data = temp->data;
  stack->top = temp->next;
  free(temp);
  stack->size--;
  return data;
}

// Check if the stack is empty
int stack_is_empty(stack_t *stack) {
  return stack->size == 0;
}

// Reverse a string using a stack
char *reverse_string(char *str) {
  stack_t *stack = stack_new();
  for (int i = 0; i < strlen(str); i++) {
    stack_push(stack, str[i]);
  }
  char *reversed_str = malloc(strlen(str) + 1);
  int i = 0;
  while (!stack_is_empty(stack)) {
    reversed_str[i++] = stack_pop(stack);
  }
  reversed_str[i] = '\0';
  return reversed_str;
}

// Print a menu of options
void print_menu() {
  printf("1. Reverse a string\n");
  printf("2. Exit\n");
}

// Get the user's input
int get_input() {
  int input;
  printf("Enter your choice: ");
  scanf("%d", &input);
  return input;
}

// Run the program
int main() {
  int running = 1;
  while (running) {
    print_menu();
    int input = get_input();
    switch (input) {
      case 1: {
        char str[MAX_SIZE];
        printf("Enter a string to reverse: ");
        scanf("%s", str);
        char *reversed_str = reverse_string(str);
        printf("Reversed string: %s\n", reversed_str);
        free(reversed_str);
        break;
      }
      case 2:
        running = 0;
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}