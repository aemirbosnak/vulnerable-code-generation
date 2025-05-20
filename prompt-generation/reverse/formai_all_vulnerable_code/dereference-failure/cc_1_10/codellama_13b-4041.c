//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>

  // Define a structure for a node in the binary search tree
  typedef struct node {
    int key;
    struct node *left;
    struct node *right;
  } Node;

  // Function to create a new node
  Node* create_node(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  // Function to insert a node into the binary search tree
  void insert_node(Node **root, int key) {
    if (*root == NULL) {
      *root = create_node(key);
      return;
    }

    if (key < (*root)->key) {
      insert_node(&(*root)->left, key);
    } else {
      insert_node(&(*root)->right, key);
    }
  }

  // Function to search for a node in the binary search tree
  Node* search_node(Node *root, int key) {
    if (root == NULL) {
      return NULL;
    }

    if (root->key == key) {
      return root;
    }

    if (key < root->key) {
      return search_node(root->left, key);
    } else {
      return search_node(root->right, key);
    }
  }

  // Function to delete a node from the binary search tree
  void delete_node(Node **root, int key) {
    if (*root == NULL) {
      return;
    }

    if ((*root)->key == key) {
      Node *temp = *root;
      *root = NULL;
      free(temp);
      return;
    }

    if (key < (*root)->key) {
      delete_node(&(*root)->left, key);
    } else {
      delete_node(&(*root)->right, key);
    }
  }

  // Function to traverse the binary search tree in order
  void traverse_tree(Node *root) {
    if (root == NULL) {
      return;
    }

    traverse_tree(root->left);
    printf("%d\n", root->key);
    traverse_tree(root->right);
  }

  // Main function
  int main() {
    Node *root = NULL;

    // Insert some nodes into the binary search tree
    insert_node(&root, 5);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 2);
    insert_node(&root, 4);

    // Search for a node in the binary search tree
    Node *node = search_node(root, 4);
    if (node != NULL) {
      printf("Found node with key %d\n", node->key);
    } else {
      printf("Node with key 4 not found\n");
    }

    // Delete a node from the binary search tree
    delete_node(&root, 4);

    // Traverse the binary search tree in order
    traverse_tree(root);

    return 0;
  }