//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a node in the network
struct node {
  int id;
  char *name;
  struct node *next;
};

// Function to create a new node
struct node* create_node(int id, char *name) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->id = id;
  new_node->name = name;
  new_node->next = NULL;
  return new_node;
}

// Function to add a node to the network
void add_node(struct node *head, int id, char *name) {
  struct node *new_node = create_node(id, name);
  if (head == NULL) {
    head = new_node;
  } else {
    struct node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Function to print the network
void print_network(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("Node: %d (%s)\n", current->id, current->name);
    current = current->next;
  }
}

int main() {
  struct node *head = NULL;
  add_node(head, 1, "Node 1");
  add_node(head, 2, "Node 2");
  add_node(head, 3, "Node 3");
  add_node(head, 4, "Node 4");
  add_node(head, 5, "Node 5");
  print_network(head);
  return 0;
}