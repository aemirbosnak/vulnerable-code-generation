//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* insert(struct node* root, int data) {
  if (root == NULL) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

void inorder(struct node* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
  struct node* root = NULL;

  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 7);
  root = insert(root, 6);
  root = insert(root, 8);

  inorder(root);

  return 0;
}