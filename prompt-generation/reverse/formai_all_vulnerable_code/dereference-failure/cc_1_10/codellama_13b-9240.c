//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: surprised
/*
 * Program to demonstrate the use of binary search trees in C
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void insert(struct node **root, int value) {
  if (*root == NULL) {
    *root = (struct node *)malloc(sizeof(struct node));
    (*root)->data = value;
    (*root)->left = (*root)->right = NULL;
  } else if (value < (*root)->data) {
    insert(&(*root)->left, value);
  } else {
    insert(&(*root)->right, value);
  }
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  int i, n;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int value;
    printf("Enter element %d: ", i + 1);
    scanf("%d", &value);
    insert(&root, value);
  }

  printf("Inorder traversal of the constructed tree: ");
  inorder(root);
  printf("\n");

  return 0;
}