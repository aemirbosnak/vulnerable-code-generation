//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* node, int data) {
  if (node == NULL) {
    return newNode(data);
  }
  if (data < node->data) {
    node->left = insert(node->left, data);
  } else {
    node->right = insert(node->right, data);
  }
  return node;
}

void inorder(Node* node) {
  if (node == NULL) {
    return;
  }
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

int main() {
  Node* root = NULL;
  int choice, num;
  do {
    printf("\n\n\t\tMENU\n");
    printf("1. Insert Element\n");
    printf("2. Inorder Traversal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        root = insert(root, num);
        printf("%d inserted successfully\n", num);
        break;
      case 2:
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 3:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Try again\n");
    }
  } while(1);
  return 0;
}