//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(Node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }

  if ((*root)->data < data) {
    insert_node(&(*root)->right, data);
  } else {
    insert_node(&(*root)->left, data);
  }
}

void inorder_traversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

int main() {
  Node *root = NULL;
  int arr[] = {2, 1, 3, 5, 7, 4, 6, 9};

  for (int i = 0; i < 8; i++) {
    insert_node(&root, arr[i]);
  }

  inorder_traversal(root);
  printf("\n");

  return 0;
}