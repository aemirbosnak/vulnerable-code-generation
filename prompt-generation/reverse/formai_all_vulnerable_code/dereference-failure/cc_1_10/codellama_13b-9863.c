//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Cryptic
// C Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

// Create a new node
Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a node into the tree
void insert(Node** root, int data) {
  if (*root == NULL) {
    *root = newNode(data);
    return;
  }

  Node* current = *root;
  Node* parent;

  while (1) {
    parent = current;
    if (data < current->data) {
      current = current->left;
      if (current == NULL) {
        parent->left = newNode(data);
        return;
      }
    } else {
      current = current->right;
      if (current == NULL) {
        parent->right = newNode(data);
        return;
      }
    }
  }
}

// Search for a node in the tree
Node* search(Node* root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (root->data == data) {
    return root;
  }

  if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Delete a node from the tree
void delete(Node** root, int data) {
  if (*root == NULL) {
    return;
  }

  if ((*root)->data == data) {
    if ((*root)->left == NULL && (*root)->right == NULL) {
      free(*root);
      *root = NULL;
      return;
    } else if ((*root)->left == NULL) {
      Node* temp = *root;
      *root = (*root)->right;
      free(temp);
      return;
    } else if ((*root)->right == NULL) {
      Node* temp = *root;
      *root = (*root)->left;
      free(temp);
      return;
    }
  }

  if (data < (*root)->data) {
    delete(&(*root)->left, data);
  } else {
    delete(&(*root)->right, data);
  }
}

int main() {
  Node* root = NULL;

  // Insert elements
  insert(&root, 10);
  insert(&root, 20);
  insert(&root, 30);
  insert(&root, 40);
  insert(&root, 50);
  insert(&root, 25);

  // Search for an element
  Node* node = search(root, 25);
  if (node != NULL) {
    printf("Element found: %d\n", node->data);
  } else {
    printf("Element not found\n");
  }

  // Delete an element
  delete(&root, 20);

  // Search for an element again
  node = search(root, 20);
  if (node != NULL) {
    printf("Element found: %d\n", node->data);
  } else {
    printf("Element not found\n");
  }

  return 0;
}