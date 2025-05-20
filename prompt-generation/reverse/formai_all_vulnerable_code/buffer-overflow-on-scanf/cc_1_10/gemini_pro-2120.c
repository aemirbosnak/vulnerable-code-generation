//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc failed.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct node *insert_node(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void inorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

int main() {
  struct node *root = NULL;
  int n, data;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter the data: ");
    scanf("%d", &data);
    root = insert_node(root, data);
  }
  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");
  return 0;
}