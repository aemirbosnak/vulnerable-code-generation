//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
/*
 * Romeo and Juliet style Binary Search Tree example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[20];
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(char* name) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* root, char* name) {
  if (root == NULL) {
    return createNode(name);
  }
  if (strcmp(name, root->name) < 0) {
    root->left = insert(root->left, name);
  } else if (strcmp(name, root->name) > 0) {
    root->right = insert(root->right, name);
  }
  return root;
}

void inorder(struct Node* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%s ", root->name);
  inorder(root->right);
}

int main() {
  struct Node* root = NULL;
  root = insert(root, "Tybalt");
  root = insert(root, "Capulet");
  root = insert(root, "Juliet");
  root = insert(root, "Romeo");
  inorder(root);
  return 0;
}