//FormAI DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

struct treeNode {
  int data;
  struct treeNode *left, *right;
};

struct treeNode *newNode(int data) {
  struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void insert(struct treeNode **root, int data) {
  if (*root == NULL) {
    *root = newNode(data);
    return;
  }
  if (data < (*root)->data)
    insert(&((*root)->left), data);
  else
    insert(&((*root)->right), data);
}

void printTree(struct treeNode *root) {
  if (root == NULL)
    return;
  printf("%d\n", root->data);
  printTree(root->left);
  printTree(root->right);
}

void search(struct treeNode *root, int data) {
  if (root == NULL) {
    printf("%d not found\n", data);
    return;
  }
  if (root->data == data) {
    printf("%d found\n", data);
    return;
  }
  if (data < root->data)
    search(root->left, data);
  else
    search(root->right, data);
}

int main() {
  struct treeNode *root = NULL;
  insert(&root, 5);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 1);
  insert(&root, 9);
  insert(&root, 2);
  insert(&root, 6);
  insert(&root, 4);
  printf("Binary Search Tree\n");
  printf("------------------\n");
  printTree(root);
  int choice;
  do {
    printf("\n1. Search\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter number to search: ");
        int num;
        scanf("%d", &num);
        search(root, num);
        break;
      case 2:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  } while (1);
  return 0;
}