//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
// Binary Search Tree Program

#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Function to create a new node
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a node into the tree
void insert_node(struct node *root, int data) {
  if (root == NULL) {
    root = create_node(data);
  } else if (data < root->data) {
    insert_node(root->left, data);
  } else {
    insert_node(root->right, data);
  }
}

// Function to print the tree
void print_tree(struct node *root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }
}

// Function to find the minimum value in the tree
int find_min(struct node *root) {
  if (root == NULL) {
    return -1;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}

// Function to find the maximum value in the tree
int find_max(struct node *root) {
  if (root == NULL) {
    return -1;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root->data;
}

// Function to delete a node from the tree
void delete_node(struct node *root, int data) {
  if (root == NULL) {
    return;
  }
  if (data < root->data) {
    delete_node(root->left, data);
  } else if (data > root->data) {
    delete_node(root->right, data);
  } else {
    // Case 1: No children
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      free(temp);
    }
    // Case 3: Two children
    else {
      int temp = find_min(root->right);
      root->data = temp;
      delete_node(root->right, temp);
    }
  }
}

int main() {
  struct node *root = NULL;

  // Insert nodes
  insert_node(root, 10);
  insert_node(root, 20);
  insert_node(root, 30);
  insert_node(root, 40);
  insert_node(root, 50);

  // Print the tree
  print_tree(root);

  // Find the minimum and maximum values
  int min = find_min(root);
  int max = find_max(root);
  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);

  // Delete a node
  delete_node(root, 40);

  // Print the tree again
  print_tree(root);

  return 0;
}