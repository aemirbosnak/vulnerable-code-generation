//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: shocked
// Binary Search Tree (BST) Example Program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

// Create a new node
node_t *create_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node in the BST
void insert_node(node_t **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }

  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

// Print the BST in pre-order traversal
void print_pre_order(node_t *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

// Print the BST in in-order traversal
void print_in_order(node_t *root) {
  if (root == NULL) {
    return;
  }

  print_in_order(root->left);
  printf("%d ", root->data);
  print_in_order(root->right);
}

// Print the BST in post-order traversal
void print_post_order(node_t *root) {
  if (root == NULL) {
    return;
  }

  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->data);
}

// Print the BST in level-order traversal
void print_level_order(node_t *root) {
  if (root == NULL) {
    return;
  }

  node_t *current = root;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->left;
  }

  printf("\n");
}

int main() {
  node_t *root = NULL;

  insert_node(&root, 5);
  insert_node(&root, 3);
  insert_node(&root, 7);
  insert_node(&root, 2);
  insert_node(&root, 4);
  insert_node(&root, 6);

  printf("Pre-order traversal: ");
  print_pre_order(root);
  printf("\n");

  printf("In-order traversal: ");
  print_in_order(root);
  printf("\n");

  printf("Post-order traversal: ");
  print_post_order(root);
  printf("\n");

  printf("Level-order traversal: ");
  print_level_order(root);
  printf("\n");

  return 0;
}