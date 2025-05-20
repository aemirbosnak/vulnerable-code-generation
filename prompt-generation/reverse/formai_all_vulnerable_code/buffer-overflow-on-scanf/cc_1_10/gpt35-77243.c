//FormAI DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node *newNode(int data) {
   struct node *temp = (struct node*)malloc(sizeof(struct node));
   temp->data = data;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

void insert(struct node **tree, int data) {
   if (*tree == NULL) {
      *tree = newNode(data);
      return;
   }
   if (data < (*tree)->data)
      insert(&((*tree)->left), data);
   else if (data > (*tree)->data)
      insert(&((*tree)->right), data);
}

void inorderTraversal(struct node *tree) {
   if (tree) {
      inorderTraversal(tree->left);
      printf("%d -> ", tree->data);
      inorderTraversal(tree->right);
   }
}

int search(struct node *tree, int data) {
   if (tree == NULL)
      return 0;
   if (data == tree->data)
      return 1;
   if (data < tree->data)
      return search(tree->left, data);
   else
      return search(tree->right, data);
}

int main() {
   int data;
   struct node *root = NULL;

   // Inserting elements into the tree
   insert(&root, 20);
   insert(&root, 10);
   insert(&root, 30);
   insert(&root, 25);
   insert(&root, 5);
   insert(&root, 15);
   insert(&root, 35);

   // Inorder traversal of the binary search tree
   printf("Inorder traversal:\n");
   inorderTraversal(root);
   printf("NULL\n\n");

   // Searching for an element in the tree
   printf("Enter element to search: ");
   scanf("%d", &data);
   if (search(root, data))
      printf("Element is present in the tree.\n");
   else
      printf("Element is not present in the tree.\n");

   return 0;
}