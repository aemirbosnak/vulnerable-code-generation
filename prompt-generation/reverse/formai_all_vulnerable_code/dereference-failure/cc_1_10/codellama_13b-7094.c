//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

int find_node(struct Node *root, int data) {
  if (root == NULL) {
    return -1;
  }

  if (root->data == data) {
    return 1;
  }

  if (root->data > data) {
    return find_node(root->left, data);
  } else {
    return find_node(root->right, data);
  }
}

struct Node* insert_node(struct Node *root, int data) {
  if (root == NULL) {
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = data;
    root->left = root->right = NULL;
    return root;
  }

  if (root->data > data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }

  return root;
}

void inorder_traversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

int main() {
  struct Node *root = NULL;
  root = insert_node(root, 5);
  root = insert_node(root, 3);
  root = insert_node(root, 7);
  root = insert_node(root, 2);
  root = insert_node(root, 4);
  root = insert_node(root, 6);
  root = insert_node(root, 8);

  printf("Inorder traversal of the BST: ");
  inorder_traversal(root);
  printf("\n");

  int data = 6;
  if (find_node(root, data) == 1) {
    printf("Data %d found in the BST.\n", data);
  } else {
    printf("Data %d not found in the BST.\n", data);
  }

  return 0;
}