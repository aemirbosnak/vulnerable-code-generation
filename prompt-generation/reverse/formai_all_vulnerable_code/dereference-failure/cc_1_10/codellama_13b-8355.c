//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

bool search(Node* root, int key) {
  if (root == NULL) return false;
  if (root->key == key) return true;
  if (root->key < key) return search(root->left, key);
  return search(root->right, key);
}

void insert(Node** root, int key) {
  if (*root == NULL) {
    *root = malloc(sizeof(Node));
    (*root)->key = key;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return;
  }
  if ((*root)->key > key) insert(&(*root)->left, key);
  else if ((*root)->key < key) insert(&(*root)->right, key);
  else return;
}

void print(Node* root) {
  if (root == NULL) return;
  print(root->left);
  printf("%d ", root->key);
  print(root->right);
}

int main() {
  Node* root = NULL;
  insert(&root, 10);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 12);
  insert(&root, 20);
  insert(&root, 17);
  insert(&root, 25);
  print(root);
  printf("\n");
  printf("%d\n", search(root, 10));
  printf("%d\n", search(root, 20));
  printf("%d\n", search(root, 15));
  return 0;
}