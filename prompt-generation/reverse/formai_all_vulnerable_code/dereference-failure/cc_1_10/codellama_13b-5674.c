//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: peaceful
// Binary search tree example program
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Function to insert a new node into the tree
void insert(Node **root, int data) {
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else if (data < (*root)->data) {
    insert(&(*root)->left, data);
  } else {
    insert(&(*root)->right, data);
  }
}

// Function to search for a node in the tree
Node *search(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Function to delete a node from the tree
void delete(Node **root, int data) {
  if (*root == NULL) {
    return;
  } else if ((*root)->data == data) {
    Node *temp = *root;
    if ((*root)->left == NULL) {
      *root = (*root)->right;
    } else if ((*root)->right == NULL) {
      *root = (*root)->left;
    } else {
      Node *temp = (*root)->left;
      while (temp->right != NULL) {
        temp = temp->right;
      }
      temp->right = (*root)->right;
      *root = (*root)->left;
    }
    free(temp);
  } else if (data < (*root)->data) {
    delete(&(*root)->left, data);
  } else {
    delete(&(*root)->right, data);
  }
}

// Function to print the tree in order
void printInOrder(Node *root) {
  if (root == NULL) {
    return;
  }
  printInOrder(root->left);
  printf("%d ", root->data);
  printInOrder(root->right);
}

int main() {
  Node *root = NULL;

  // Insert elements into the tree
  insert(&root, 10);
  insert(&root, 20);
  insert(&root, 30);
  insert(&root, 40);
  insert(&root, 50);

  // Search for a node in the tree
  Node *node = search(root, 40);
  if (node == NULL) {
    printf("Element not found\n");
  } else {
    printf("Element found: %d\n", node->data);
  }

  // Delete a node from the tree
  delete(&root, 40);

  // Print the tree in order
  printf("In order: ");
  printInOrder(root);
  printf("\n");

  return 0;
}