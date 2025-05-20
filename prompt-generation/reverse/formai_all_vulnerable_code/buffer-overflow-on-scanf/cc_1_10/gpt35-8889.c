//FormAI DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>
 #include <stdlib.h>

 struct Node {
     int data;
     struct Node* left;
     struct Node* right;
 };
 
 // Function to create a new node
 struct Node* newNode(int data) {
     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return node;
 }
 
 // Function to insert a new node in the tree
 struct Node* insert(struct Node* node, int data) {
     // If the tree is empty, return a new node
     if (node == NULL) {
         return newNode(data);
     }
 
     // Otherwise, recur down the tree
     if (data < node->data) {
         node->left = insert(node->left, data);
     }
     else if (data > node->data) {
         node->right = insert(node->right, data);
     }
 
     // Return the unchanged node pointer
     return node;
 }
 
 // Function to search a node in the tree
 struct Node* search(struct Node* node, int data) {
     // If the tree is empty or the data is present at the root
     if (node == NULL || node->data == data) {
         return node;
     }
 
     // If the data is greater than the root, recur down the right subtree
     if (node->data < data) {
         return search(node->right, data);
     }
 
     // Else, recur down the left subtree
     return search(node->left, data);
 }
 
 // Function to print inorder tree traversal
 void inorder(struct Node* node) {
     if (node != NULL) {
         inorder(node->left);
         printf("%d ", node->data);
         inorder(node->right);
     }
 }
 
 // Main function
 int main() {
     struct Node* root = NULL;
     int choice=0,num;
     printf("Binary Search Tree Program\n");
     do
     {
         printf("Enter your choice\n1)insert\n2)search\n3)inorder traversal\n4)exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
                 printf("Enter the value to insert\n");
                 scanf("%d",&num);
                 root = insert(root,num);
                 break;
             case 2:
                 printf("Enter the value to search\n");
                 scanf("%d",&num);
                 if(search(root,num)==NULL)
                     printf("Value not found\n");
                 else
                     printf("Value found\n");
                 break;
             case 3:
                 printf("Inorder traversal:\n");
                 inorder(root);
                 printf("\n");
                 break;
             case 4:
                 printf("Exiting program!\n");
                 break;
             default:
                 printf("Invalid choice!\n");
                 break;
         }
     }
     while(choice!=4);
     return 0;
 }