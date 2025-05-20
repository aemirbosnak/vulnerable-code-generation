//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
// VisualizeDataStructures.c

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in a linked list
typedef struct node {
  int data;
  struct node *next;
} Node;

// Define a structure to represent a tree node
typedef struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
} TreeNode;

// Define a structure to represent a graph
typedef struct graph {
  int num_vertices;
  int num_edges;
  int **adjacency_matrix;
} Graph;

// Define a structure to represent a matrix
typedef struct matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

// Define a function to print a linked list
void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Define a function to print a tree
void print_tree(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_tree(root->left);
  print_tree(root->right);
}

// Define a function to print a graph
void print_graph(Graph *g) {
  printf("Vertices: ");
  for (int i = 0; i < g->num_vertices; i++) {
    printf("%d ", i);
  }
  printf("\nEdges: ");
  for (int i = 0; i < g->num_vertices; i++) {
    for (int j = 0; j < g->num_vertices; j++) {
      if (g->adjacency_matrix[i][j] == 1) {
        printf("%d-%d ", i, j);
      }
    }
  }
  printf("\n");
}

// Define a function to print a matrix
void print_matrix(Matrix *m) {
  printf("Matrix:\n");
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%d ", m->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Linked list example
  Node *head = NULL;
  Node *current = NULL;
  for (int i = 0; i < 5; i++) {
    current = malloc(sizeof(Node));
    current->data = i;
    current->next = head;
    head = current;
  }
  print_list(head);

  // Tree example
  TreeNode *root = NULL;
  for (int i = 0; i < 5; i++) {
    TreeNode *current = malloc(sizeof(TreeNode));
    current->data = i;
    current->left = NULL;
    current->right = NULL;
    if (root == NULL) {
      root = current;
    } else {
      TreeNode *parent = root;
      while (parent != NULL) {
        if (parent->left == NULL) {
          parent->left = current;
          break;
        } else if (parent->right == NULL) {
          parent->right = current;
          break;
        }
        parent = parent->left == NULL ? parent->right : parent->left;
      }
    }
  }
  print_tree(root);

  // Graph example
  Graph *g = malloc(sizeof(Graph));
  g->num_vertices = 5;
  g->num_edges = 5;
  g->adjacency_matrix = malloc(g->num_vertices * sizeof(int *));
  for (int i = 0; i < g->num_vertices; i++) {
    g->adjacency_matrix[i] = malloc(g->num_vertices * sizeof(int));
  }
  for (int i = 0; i < g->num_edges; i++) {
    int v1 = i;
    int v2 = (i + 1) % g->num_vertices;
    g->adjacency_matrix[v1][v2] = 1;
  }
  print_graph(g);

  // Matrix example
  Matrix *m = malloc(sizeof(Matrix));
  m->rows = 3;
  m->cols = 3;
  m->data = malloc(m->rows * sizeof(int *));
  for (int i = 0; i < m->rows; i++) {
    m->data[i] = malloc(m->cols * sizeof(int));
    for (int j = 0; j < m->cols; j++) {
      m->data[i][j] = i * j;
    }
  }
  print_matrix(m);

  return 0;
}