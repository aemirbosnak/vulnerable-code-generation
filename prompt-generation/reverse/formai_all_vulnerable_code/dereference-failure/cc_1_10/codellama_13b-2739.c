//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: puzzling
/*
 * A unique C Binary search trees example program in a puzzling style
 */

#include <stdio.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *insert(node_t *root, int data) {
  if (root == NULL) {
    root = malloc(sizeof(node_t));
    root->data = data;
    root->left = root->right = NULL;
    return root;
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

int search(node_t *root, int data) {
  if (root == NULL) {
    return 0;
  }

  if (data == root->data) {
    return 1;
  }

  if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void delete(node_t *root) {
  if (root == NULL) {
    return;
  }

  delete(root->left);
  delete(root->right);
  free(root);
}

int main() {
  node_t *root = NULL;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    root = insert(root, arr[i]);
  }

  int key = 4;
  if (search(root, key) == 1) {
    printf("%d found in the tree.\n", key);
  } else {
    printf("%d not found in the tree.\n", key);
  }

  delete(root);
  return 0;
}