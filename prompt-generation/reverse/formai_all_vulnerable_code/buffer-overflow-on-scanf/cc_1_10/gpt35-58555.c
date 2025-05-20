//FormAI DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return createNode(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

int search(Node* root, int data) {
  if (root == NULL) {
    return 0;
  } else if (root->data == data) {
    return 1;
  } else if (data < root->data) {
    return search(root->left, data);
  } else if (data > root->data) {
    return search(root->right, data);
  }
}

void printInOrder(Node* root) {
  if (root != NULL) {
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
  }
}

int main() {
  Node* root = NULL;
  int choice, x;

  printf("*** BINARY SEARCH TREE ***\n");
  printf("1. Insert\n");
  printf("2. Search\n");
  printf("3. Print\n");
  printf("4. Exit\n");

  while (1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to insert: ");
        scanf("%d", &x);
        root = insert(root, x);
        break;
      case 2:
        printf("Enter the value to search: ");
        scanf("%d", &x);
        if (search(root, x)) {
          printf("Value found!\n");
        } else {
          printf("Value not found.\n");
        }
        break;
      case 3:
        printInOrder(root);
        printf("\n");
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}