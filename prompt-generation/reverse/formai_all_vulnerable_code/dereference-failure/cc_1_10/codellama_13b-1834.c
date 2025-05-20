//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <time.h>
  #include <math.h>

  // Structures for nodes and edges
  struct node {
      int id;
      int data;
      struct node* next;
  };

  struct edge {
      struct node* source;
      struct node* destination;
      int weight;
      struct edge* next;
  };

  // Functions for creating and manipulating nodes and edges
  struct node* create_node(int id, int data) {
      struct node* new_node = (struct node*)malloc(sizeof(struct node));
      new_node->id = id;
      new_node->data = data;
      new_node->next = NULL;
      return new_node;
  }

  struct edge* create_edge(struct node* source, struct node* destination, int weight) {
      struct edge* new_edge = (struct edge*)malloc(sizeof(struct edge));
      new_edge->source = source;
      new_edge->destination = destination;
      new_edge->weight = weight;
      new_edge->next = NULL;
      return new_edge;
  }

  void add_edge(struct node* source, struct node* destination, int weight) {
      struct edge* new_edge = create_edge(source, destination, weight);
      new_edge->next = source->next;
      source->next = new_edge;
  }

  // Function for printing the graph
  void print_graph(struct node* head) {
      struct node* current = head;
      while (current != NULL) {
          printf("Node %d: ", current->id);
          struct edge* edge = current->next;
          while (edge != NULL) {
              printf("%d ", edge->destination->id);
              edge = edge->next;
          }
          printf("\n");
          current = current->next;
      }
  }

  int main() {
      // Initialize the graph
      struct node* head = create_node(0, 0);
      struct node* node1 = create_node(1, 1);
      struct node* node2 = create_node(2, 2);
      struct node* node3 = create_node(3, 3);
      struct node* node4 = create_node(4, 4);
      struct node* node5 = create_node(5, 5);

      // Add edges to the graph
      add_edge(head, node1, 1);
      add_edge(head, node2, 2);
      add_edge(node1, node3, 3);
      add_edge(node1, node4, 4);
      add_edge(node2, node5, 5);
      add_edge(node3, node5, 6);

      // Print the graph
      print_graph(head);

      return 0;
  }