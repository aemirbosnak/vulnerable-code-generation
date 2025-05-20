//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: introspective
// Unique C Binary search tree example program
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Insert node into binary search tree
struct node* insert(struct node* root, int data) {
  // If tree is empty, create new node and return it
  if (root == NULL) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  // If data is less than root, insert it into left subtree
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    // If data is greater than root, insert it into right subtree
    root->right = insert(root->right, data);
  }

  // Return updated root node
  return root;
}

// Find node with given data in binary search tree
struct node* find(struct node* root, int data) {
  // If tree is empty, return NULL
  if (root == NULL) {
    return NULL;
  }

  // If data is found, return node
  if (data == root->data) {
    return root;
  }

  // If data is less than root, search left subtree
  if (data < root->data) {
    return find(root->left, data);
  } else {
    // If data is greater than root, search right subtree
    return find(root->right, data);
  }
}

// Delete node with given data in binary search tree
struct node* delete(struct node* root, int data) {
  // If tree is empty, return NULL
  if (root == NULL) {
    return NULL;
  }

  // If data is found, delete node and return updated root
  if (data == root->data) {
    struct node* temp = root->left;
    free(root);
    return temp;
  }

  // If data is less than root, delete from left subtree
  if (data < root->data) {
    root->left = delete(root->left, data);
  } else {
    // If data is greater than root, delete from right subtree
    root->right = delete(root->right, data);
  }

  // Return updated root node
  return root;
}

// Traverse binary search tree in-order
void inOrder(struct node* root) {
  // If tree is empty, return
  if (root == NULL) {
    return;
  }

  // Traverse left subtree
  inOrder(root->left);

  // Print data
  printf("%d ", root->data);

  // Traverse right subtree
  inOrder(root->right);
}

int main() {
  // Create binary search tree
  struct node* root = NULL;

  // Insert elements
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  // Find element
  struct node* found = find(root, 60);
  printf("Found: %d\n", found->data);

  // Delete element
  root = delete(root, 60);

  // Traverse tree
  inOrder(root);

  // Free memory
  free(root);

  return 0;
}