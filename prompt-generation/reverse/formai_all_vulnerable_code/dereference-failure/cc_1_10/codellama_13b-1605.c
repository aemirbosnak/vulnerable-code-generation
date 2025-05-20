//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <time.h>

  typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
  } Node;

  void insert(Node **root, int data) {
    if (*root == NULL) {
      *root = malloc(sizeof(Node));
      (*root)->data = data;
      (*root)->left = NULL;
      (*root)->right = NULL;
    } else if (data < (*root)->data) {
      insert(&(*root)->left, data);
    } else {
      insert(&(*root)->right, data);
    }
  }

  bool search(Node *root, int data) {
    if (root == NULL) {
      return false;
    } else if (data == root->data) {
      return true;
    } else if (data < root->data) {
      return search(root->left, data);
    } else {
      return search(root->right, data);
    }
  }

  void destroy(Node *root) {
    if (root != NULL) {
      destroy(root->left);
      destroy(root->right);
      free(root);
    }
  }

  int main() {
    srand(time(NULL));

    Node *root = NULL;
    for (int i = 0; i < 10; i++) {
      insert(&root, rand() % 100);
    }

    for (int i = 0; i < 10; i++) {
      int data = rand() % 100;
      printf("%d ", data);
      if (search(root, data)) {
        printf("found\n");
      } else {
        printf("not found\n");
      }
    }

    destroy(root);

    return 0;
  }