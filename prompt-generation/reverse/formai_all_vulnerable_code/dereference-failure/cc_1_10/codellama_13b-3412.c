//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
// Cyberpunk-style Binary Search Tree program

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insertNode(struct node **root, int data) {
  if (*root == NULL) {
    *root = createNode(data);
    return;
  }
  if (data <= (*root)->data) {
    insertNode(&(*root)->left, data);
  } else {
    insertNode(&(*root)->right, data);
  }
}

void printInOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  printInOrder(root->left);
  printf("%d ", root->data);
  printInOrder(root->right);
}

void printPostOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  printPostOrder(root->left);
  printPostOrder(root->right);
  printf("%d ", root->data);
}

int main() {
  struct node *root = NULL;
  int data[] = {4, 2, 6, 1, 3, 5, 7};
  for (int i = 0; i < 7; i++) {
    insertNode(&root, data[i]);
  }
  printf("Inorder traversal:\n");
  printInOrder(root);
  printf("\nPostorder traversal:\n");
  printPostOrder(root);
  return 0;
}