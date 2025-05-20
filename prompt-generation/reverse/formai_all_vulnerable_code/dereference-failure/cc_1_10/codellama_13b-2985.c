//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: curious
// Unique C Binary search trees example program in a curious style
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node** root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }

  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    insert_node(&(*root)->right, data);
  }
}

void print_tree(node* root) {
  if (root == NULL) {
    return;
  }

  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}

int main() {
  node* root = NULL;
  insert_node(&root, 5);
  insert_node(&root, 3);
  insert_node(&root, 7);
  insert_node(&root, 2);
  insert_node(&root, 4);
  insert_node(&root, 6);

  print_tree(root);
  printf("\n");

  return 0;
}