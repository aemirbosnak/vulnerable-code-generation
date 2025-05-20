//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: retro
// Retro-style Binary Search Tree Program

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a new node in the binary search tree
void insert(struct Node** root, int data) {
  // If the root is NULL, create a new node and make it the root
  if (*root == NULL) {
    *root = createNode(data);
    return;
  }

  // If the data is less than the root node, recur for the left subtree
  if (data < (*root)->data) {
    insert(&(*root)->left, data);
  }

  // If the data is greater than the root node, recur for the right subtree
  else {
    insert(&(*root)->right, data);
  }
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int data) {
  // If the root is NULL, return NULL
  if (root == NULL) {
    return NULL;
  }

  // If the data is found in the root node, return the root node
  if (root->data == data) {
    return root;
  }

  // If the data is less than the root node, recur for the left subtree
  if (data < root->data) {
    return search(root->left, data);
  }

  // If the data is greater than the root node, recur for the right subtree
  else {
    return search(root->right, data);
  }
}

// Function to delete a node from the binary search tree
struct Node* delete(struct Node* root, int data) {
  // If the root is NULL, return NULL
  if (root == NULL) {
    return NULL;
  }

  // If the data is found in the root node, delete the root node
  if (root->data == data) {
    struct Node* temp = root;
    if (root->left == NULL) {
      root = root->right;
    }
    else if (root->right == NULL) {
      root = root->left;
    }
    else {
      struct Node* temp = root->left;
      while (temp->right != NULL) {
        temp = temp->right;
      }
      temp->right = root->right;
      root = root->left;
    }
    free(temp);
    return root;
  }

  // If the data is less than the root node, recur for the left subtree
  if (data < root->data) {
    return delete(root->left, data);
  }

  // If the data is greater than the root node, recur for the right subtree
  else {
    return delete(root->right, data);
  }
}

// Function to display the nodes of the binary search tree
void display(struct Node* root) {
  // If the root is NULL, return
  if (root == NULL) {
    return;
  }

  // Display the data in the root node
  printf("%d ", root->data);

  // Recur for the left subtree
  display(root->left);

  // Recur for the right subtree
  display(root->right);
}

int main() {
  // Create a new binary search tree
  struct Node* root = NULL;

  // Insert elements in the binary search tree
  insert(&root, 5);
  insert(&root, 10);
  insert(&root, 2);
  insert(&root, 1);
  insert(&root, 3);

  // Search for an element in the binary search tree
  struct Node* node = search(root, 3);
  if (node != NULL) {
    printf("Found %d\n", node->data);
  }
  else {
    printf("Element not found\n");
  }

  // Delete an element from the binary search tree
  root = delete(root, 2);

  // Display the elements in the binary search tree
  display(root);

  return 0;
}