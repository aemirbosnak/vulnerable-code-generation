//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  typedef struct node {
    int data;
    struct node *left;
    struct node *right;
  } Node;

  void print_tree(Node *root) {
    if (root == NULL) {
      return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }

  void insert_node(Node **root, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
      *root = new_node;
      return;
    }

    Node *current = *root;
    while (current != NULL) {
      if (current->data == value) {
        free(new_node);
        return;
      } else if (current->data > value) {
        if (current->left == NULL) {
          current->left = new_node;
          return;
        }
        current = current->left;
      } else {
        if (current->right == NULL) {
          current->right = new_node;
          return;
        }
        current = current->right;
      }
    }
  }

  int main() {
    Node *root = NULL;

    insert_node(&root, 5);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 1);
    insert_node(&root, 4);
    insert_node(&root, 6);
    insert_node(&root, 9);
    insert_node(&root, 2);

    print_tree(root);

    return 0;
  }