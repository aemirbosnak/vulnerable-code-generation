//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Structures
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct Tree {
  Node *root;
} Tree;

// Functions
void init_tree(Tree *tree) {
  tree->root = NULL;
}

void insert_node(Tree *tree, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree->root == NULL) {
    tree->root = new_node;
    return;
  }

  Node *current = tree->root;
  while (current != NULL) {
    if (current->data < value) {
      if (current->right == NULL) {
        current->right = new_node;
        return;
      }
      current = current->right;
    } else {
      if (current->left == NULL) {
        current->left = new_node;
        return;
      }
      current = current->left;
    }
  }
}

void inorder_traversal(Node *node) {
  if (node == NULL) {
    return;
  }

  inorder_traversal(node->left);
  printf("%d ", node->data);
  inorder_traversal(node->right);
}

void preorder_traversal(Node *node) {
  if (node == NULL) {
    return;
  }

  printf("%d ", node->data);
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

void postorder_traversal(Node *node) {
  if (node == NULL) {
    return;
  }

  postorder_traversal(node->left);
  postorder_traversal(node->right);
  printf("%d ", node->data);
}

// Main function
int main() {
  Tree tree;
  init_tree(&tree);

  int values[] = {10, 5, 15, 3, 7, 13, 18, 20, 25};
  for (int i = 0; i < 9; i++) {
    insert_node(&tree, values[i]);
  }

  printf("Inorder traversal: ");
  inorder_traversal(tree.root);
  printf("\n");

  printf("Preorder traversal: ");
  preorder_traversal(tree.root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder_traversal(tree.root);
  printf("\n");

  return 0;
}