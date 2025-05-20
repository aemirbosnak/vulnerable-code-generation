//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NODES 1000
#define LEVELS 10

typedef struct node {
  char *data;
  struct node *next;
  struct node *child;
} node_t;

int main() {
  node_t *nodes[NODES];
  char *strings[] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  int i, j, k;

  // Generate the nodes
  for (i = 0; i < NODES; i++) {
    nodes[i] = malloc(sizeof(node_t));
    nodes[i]->data = malloc(strlen(strings[i]) + 1);
    strcpy(nodes[i]->data, strings[i]);
    nodes[i]->next = NULL;
    nodes[i]->child = NULL;
  }

  // Create the tree
  for (i = 0; i < NODES; i++) {
    for (j = 0; j < LEVELS; j++) {
      if (nodes[i]->child == NULL) {
        nodes[i]->child = nodes[(i * 2) + 1];
        nodes[(i * 2) + 1]->next = nodes[(i * 2) + 2];
      }
    }
  }

  // Print the tree
  for (i = 0; i < NODES; i++) {
    printf("%s\n", nodes[i]->data);
    for (j = 0; j < LEVELS; j++) {
      if (nodes[i]->child != NULL) {
        printf("  %s\n", nodes[i]->child->data);
        for (k = 0; k < LEVELS; k++) {
          if (nodes[i]->child->child != NULL) {
            printf("    %s\n", nodes[i]->child->child->data);
          }
        }
      }
    }
  }

  // Free the nodes
  for (i = 0; i < NODES; i++) {
    free(nodes[i]->data);
    free(nodes[i]);
  }

  return 0;
}