//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node *left;
  struct _node *right;
} node;

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *insert_node(node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else if (data > root->data) {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void print_tree(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
  }
}

int main() {
  node *root = NULL;
  int data;

  printf("Enter data: ");
  while (scanf("%d", &data) != EOF) {
    root = insert_node(root, data);
  }

  printf("Inorder traversal: ");
  print_tree(root);
  printf("\n");

  return 0;
}