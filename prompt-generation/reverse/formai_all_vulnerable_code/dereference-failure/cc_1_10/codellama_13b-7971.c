//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: safe
// A unique C Data structures visualization example program in a safe style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Function to create a new node
struct node* create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a node into the tree
void insert_node(struct node **root, int data) {
  // If the root is NULL, create a new node and return
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }
  // If the data is less than the root, insert it in the left subtree
  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  }
  // If the data is greater than the root, insert it in the right subtree
  else {
    insert_node(&(*root)->right, data);
  }
}

// Function to traverse the tree
void traverse_tree(struct node *root) {
  // If the root is NULL, return
  if (root == NULL) {
    return;
  }
  // Traverse the left subtree
  traverse_tree(root->left);
  // Print the data
  printf("%d ", root->data);
  // Traverse the right subtree
  traverse_tree(root->right);
}

int main() {
  // Create a new node
  struct node *root = create_node(5);
  // Insert nodes into the tree
  insert_node(&root, 3);
  insert_node(&root, 2);
  insert_node(&root, 4);
  insert_node(&root, 1);
  insert_node(&root, 6);
  // Traverse the tree
  traverse_tree(root);
  printf("\n");
  return 0;
}