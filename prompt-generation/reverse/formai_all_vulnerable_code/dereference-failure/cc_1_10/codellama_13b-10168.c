//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
  #include <stdlib.h>

  typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
  } Node;

  Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  void insert_node(Node *root, int data) {
    if (root == NULL) {
      root = create_node(data);
      return;
    }

    if (data < root->data) {
      if (root->left == NULL) {
        root->left = create_node(data);
      } else {
        insert_node(root->left, data);
      }
    } else if (data > root->data) {
      if (root->right == NULL) {
        root->right = create_node(data);
      } else {
        insert_node(root->right, data);
      }
    }
  }

  int search_node(Node *root, int data) {
    if (root == NULL) {
      return 0;
    }

    if (data == root->data) {
      return 1;
    } else if (data < root->data) {
      return search_node(root->left, data);
    } else {
      return search_node(root->right, data);
    }
  }

  void print_node(Node *root) {
    if (root == NULL) {
      return;
    }

    print_node(root->left);
    printf("%d ", root->data);
    print_node(root->right);
  }

  int main() {
    Node *root = NULL;

    insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 20);
    insert_node(root, 15);

    printf("Binary search tree: ");
    print_node(root);
    printf("\n");

    int data = 15;
    printf("Searching for %d: ", data);
    if (search_node(root, data)) {
      printf("Found\n");
    } else {
      printf("Not found\n");
    }

    data = 25;
    printf("Searching for %d: ", data);
    if (search_node(root, data)) {
      printf("Found\n");
    } else {
      printf("Not found\n");
    }

    return 0;
  }