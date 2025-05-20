//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  // Node structure for the binary search tree
  typedef struct Node {
      int data;
      struct Node *left;
      struct Node *right;
  } Node;

  // Function to create a new node
  Node *createNode(int data) {
      Node *newNode = malloc(sizeof(Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
  }

  // Function to insert a node in the binary search tree
  void insertNode(Node **root, int data) {
      if (*root == NULL) {
          *root = createNode(data);
          return;
      }

      if ((*root)->data > data) {
          insertNode(&(*root)->left, data);
      } else {
          insertNode(&(*root)->right, data);
      }
  }

  // Function to find a node in the binary search tree
  bool findNode(Node *root, int data) {
      if (root == NULL) {
          return false;
      }

      if (root->data == data) {
          return true;
      }

      if (root->data > data) {
          return findNode(root->left, data);
      } else {
          return findNode(root->right, data);
      }
  }

  // Function to delete a node from the binary search tree
  void deleteNode(Node **root, int data) {
      if (*root == NULL) {
          return;
      }

      if ((*root)->data > data) {
          deleteNode(&(*root)->left, data);
      } else if ((*root)->data < data) {
          deleteNode(&(*root)->right, data);
      } else {
          // Node found, delete it
          if ((*root)->left == NULL && (*root)->right == NULL) {
              // No children, just delete the node
              free(*root);
              *root = NULL;
          } else if ((*root)->left == NULL) {
              // No left child, move the right child up
              Node *temp = *root;
              *root = (*root)->right;
              free(temp);
          } else if ((*root)->right == NULL) {
              // No right child, move the left child up
              Node *temp = *root;
              *root = (*root)->left;
              free(temp);
          } else {
              // Both children exist, find the in-order successor
              Node *temp = (*root)->right;
              while (temp->left != NULL) {
                  temp = temp->left;
              }
              (*root)->data = temp->data;
              deleteNode(&(*root)->right, temp->data);
          }
      }
  }

  // Main function to test the binary search tree
  int main() {
      // Create a binary search tree with the following elements:
      // 4, 2, 6, 1, 3, 5, 7
      Node *root = NULL;
      insertNode(&root, 4);
      insertNode(&root, 2);
      insertNode(&root, 6);
      insertNode(&root, 1);
      insertNode(&root, 3);
      insertNode(&root, 5);
      insertNode(&root, 7);

      // Test the findNode function
      printf("Find node with value 3: %s\n", findNode(root, 3) ? "true" : "false");
      printf("Find node with value 8: %s\n", findNode(root, 8) ? "true" : "false");

      // Test the deleteNode function
      deleteNode(&root, 3);
      printf("Find node with value 3: %s\n", findNode(root, 3) ? "true" : "false");

      return 0;
  }