//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
  #include <stdlib.h>

  struct node {
    int data;
    struct node* left;
    struct node* right;
  };

  void insert(struct node** root, int key) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
      *root = new_node;
      return;
    }

    struct node* current = *root;
    struct node* parent;
    while (current != NULL) {
      parent = current;
      if (key < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if (key < parent->data) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  }

  void pre_order(struct node* root) {
    if (root == NULL) {
      return;
    }

    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }

  void in_order(struct node* root) {
    if (root == NULL) {
      return;
    }

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }

  void post_order(struct node* root) {
    if (root == NULL) {
      return;
    }

    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }

  int main() {
    struct node* root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 6);

    printf("Pre-order traversal: ");
    pre_order(root);
    printf("\n");

    printf("In-order traversal: ");
    in_order(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order(root);
    printf("\n");

    return 0;
  }