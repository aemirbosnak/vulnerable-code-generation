//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* insert(struct node* node, int data) {

  if (node == NULL)
    return newNode(data);

  if (data < node->data)
    node->left = insert(node->left, data);

  else if (data > node->data)
    node->right = insert(node->right, data);

  return node;
}

void printPostorder(struct node* node) {
  if (node == NULL)
    return;

  printPostorder(node->left);

  printPostorder(node->right);

  printf("%d ", node->data);
}

void printInorder(struct node* node) {
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

void printPreorder(struct node* node) {
  if (node == NULL)
    return;
  printf("%d ", node->data);

  printPreorder(node->left);

  printPreorder(node->right);
}

int main() {
  printf("Welcome to the post-apocalyptic world. Here, humanity has been destroyed by a virus, which has turned everyone into zombies. The only way to survive is to navigate through the abandoned cities and find resources. Therefore, we will use a binary search tree to keep track of the resources we find. Good luck!\n\n");

  struct node* root = NULL;
  int choice, value, i, num;

  printf("How many resources did you find today? ");
  scanf("%d", &num);

  printf("Enter the resources:\n");

  for (i = 1; i <= num; ++i) {
    scanf("%d", &value);
    root = insert(root, value);
  }

  printf("\nEnter 1 to print the resources in Preorder Traversal\nEnter 2 to print the resources in Inorder Traversal\nEnter 3 to print the resources in Postorder Traversal\nEnter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1: 
      printf("Resources in Preorder Traversal: ");
      printPreorder(root);
      break;

    case 2: 
      printf("Resources in Inorder Traversal: ");
      printInorder(root);
      break;

    case 3: 
      printf("Resources in Postorder Traversal: ");
      printPostorder(root);
      break;

    default: 
      printf("Invalid choice.");
  }

  return 0;
}