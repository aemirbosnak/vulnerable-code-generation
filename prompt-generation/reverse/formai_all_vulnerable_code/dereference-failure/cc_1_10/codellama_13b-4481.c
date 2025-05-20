//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: happy
// Binary Search Trees Example Program

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

// Creates a new node with the given data
Node* create_node(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Inserts a new node with the given data into the tree
void insert(Node* node, int data) {
  if (data < node->data) {
    if (node->left == NULL) {
      node->left = create_node(data);
    } else {
      insert(node->left, data);
    }
  } else if (data > node->data) {
    if (node->right == NULL) {
      node->right = create_node(data);
    } else {
      insert(node->right, data);
    }
  }
}

// Prints the tree in an inorder fashion
void print_tree(Node* node) {
  if (node == NULL) {
    return;
  }
  print_tree(node->left);
  printf("%d ", node->data);
  print_tree(node->right);
}

// Deletes a node with the given data from the tree
void delete(Node* node, int data) {
  if (node == NULL) {
    return;
  }
  if (data < node->data) {
    delete(node->left, data);
  } else if (data > node->data) {
    delete(node->right, data);
  } else {
    if (node->left == NULL && node->right == NULL) {
      free(node);
      return;
    }
    if (node->left == NULL) {
      Node* temp = node->right;
      free(node);
      node = temp;
    } else if (node->right == NULL) {
      Node* temp = node->left;
      free(node);
      node = temp;
    } else {
      Node* temp = node->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      node->data = temp->data;
      delete(node->right, temp->data);
    }
  }
}

int main() {
  // Initialize the tree with some nodes
  Node* root = create_node(10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 3);
  insert(root, 7);
  insert(root, 12);
  insert(root, 18);

  // Print the tree
  print_tree(root);
  printf("\n");

  // Delete a node
  delete(root, 15);

  // Print the tree again
  print_tree(root);

  return 0;
}