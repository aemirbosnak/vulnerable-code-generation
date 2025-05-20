//FormAI DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* head = NULL;

/**
 * append: adds a new node with given data to the end of the linked list
 */
void append(int data) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    return;
  }

  struct node* tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
}

/**
 * printList: prints all the nodes in the linked list
 */
void printList() {
  struct node* tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
}

/**
 * main: entry point of the program
 * Parses the command line arguments and adds them to the linked list if they are valid integers.
 */
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s int1 int2 int3 ...\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    char* ptr;
    int num = strtol(argv[i], &ptr, 10);

    // check if the input string is a valid integer
    if (*ptr != '\0' || num < -2147483648 || num > 2147483647) {
      printf("Error: %s is an invalid integer.\n", argv[i]);
      continue;
    }

    append(num);
  }

  printList();
  printf("\n");

  return 0;
}