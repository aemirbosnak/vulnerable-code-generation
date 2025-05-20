//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
  #include <stdlib.h>

  struct Node {
    int data;
    struct Node *left;
    struct Node *right;
  };

  struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  void insertNode(struct Node **root, int data) {
    if (*root == NULL) {
      *root = createNode(data);
      return;
    }

    if ((*root)->data > data) {
      insertNode(&(*root)->left, data);
    } else if ((*root)->data < data) {
      insertNode(&(*root)->right, data);
    }
  }

  void inorderTraversal(struct Node *root) {
    if (root == NULL) {
      return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }

  int main() {
    struct Node *root = NULL;

    insertNode(&root, 10);
    insertNode(&root, 20);
    insertNode(&root, 30);
    insertNode(&root, 40);
    insertNode(&root, 50);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
  }