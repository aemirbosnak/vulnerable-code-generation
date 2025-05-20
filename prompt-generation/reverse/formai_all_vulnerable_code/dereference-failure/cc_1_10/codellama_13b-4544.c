//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: imaginative
/// Imaginative Binary Search Tree Program ///
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a node in the tree
void insertNode(Node* root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return;
  }
  if (data < root->data) {
    insertNode(root->left, data);
  } else {
    insertNode(root->right, data);
  }
}

// Function to search a node in the tree
Node* searchNode(Node* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == data) {
    return root;
  }
  if (data < root->data) {
    return searchNode(root->left, data);
  } else {
    return searchNode(root->right, data);
  }
}

// Function to delete a node from the tree
void deleteNode(Node* root, int data) {
  if (root == NULL) {
    return;
  }
  if (root->data == data) {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return;
    }
    if (root->left != NULL) {
      root->data = root->left->data;
      deleteNode(root->left, root->left->data);
      return;
    }
    if (root->right != NULL) {
      root->data = root->right->data;
      deleteNode(root->right, root->right->data);
      return;
    }
  }
  if (data < root->data) {
    deleteNode(root->left, data);
  } else {
    deleteNode(root->right, data);
  }
}

// Function to print the tree
void printTree(Node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  printTree(root->left);
  printTree(root->right);
}

// Driver code
int main() {
  Node* root = NULL;
  insertNode(root, 10);
  insertNode(root, 20);
  insertNode(root, 30);
  insertNode(root, 40);
  insertNode(root, 50);
  insertNode(root, 25);
  printTree(root);
  deleteNode(root, 25);
  printf("\nAfter deletion: ");
  printTree(root);
  return 0;
}