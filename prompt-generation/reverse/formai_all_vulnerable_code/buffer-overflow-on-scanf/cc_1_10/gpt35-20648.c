//FormAI DATASET v1.0 Category: Binary search trees ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

// Binary Search Tree Node Structure
struct node {
   int value;
   struct node *left;
   struct node *right;
};

// Function to create a new Binary Search Tree Node
struct node *createNode(int value) {
   struct node *temp = (struct node*)malloc(sizeof(struct node));
   temp->value = value;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

// Function to insert a new value in Binary Search Tree
struct node* insertValue(struct node* node, int value) {
   if (node == NULL) return createNode(value);
   if (value < node->value)
      node->left  = insertValue(node->left, value);
   else if (value > node->value)
      node->right = insertValue(node->right, value);
   return node;
}

// Function to search for a value in Binary Search Tree
struct node* searchValue(struct node* node, int value) {
   if (node == NULL || node->value == value)
      return node;
   if (node->value < value)
      return searchValue(node->right, value);
   return searchValue(node->left, value);
}

// Function to perform Inorder traversal of Binary Search Tree
void inOrderTraversal(struct node *node) {
   if (node != NULL) {
      inOrderTraversal(node->left);
      printf("%d ", node->value);
      inOrderTraversal(node->right);
   }
}

int main() {
   int option, value;
   struct node *root = NULL;
   printf("Binary Search Tree Program\n");
   while(1) {
      printf("\nSelect an option:\n");
      printf("1. Insert a new value\n");
      printf("2. Search for a value\n");
      printf("3. Inorder Traversal\n");
      printf("4. Exit Program\n");
      scanf("%d", &option);
      switch(option) {
         case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            root = insertValue(root, value);
            printf("Value inserted successfully!\n");
            break;
         case 2:
            printf("Enter value to be searched: ");
            scanf("%d", &value);
            if(searchValue(root, value) == NULL)
               printf("Value not found in Binary Search Tree!\n");
            else
               printf("Value found in Binary Search Tree!\n");
            break;
         case 3:
            printf("Inorder traversal of Binary Search Tree: ");
            inOrderTraversal(root);
            printf("\n");
            break;
         case 4:
            printf("Exiting Program!\n");
            exit(0);
         default:
            printf("Invalid option selected!\n");
            break;
      }
   }
   return 0;
}