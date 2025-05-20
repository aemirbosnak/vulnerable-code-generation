//FormAI DATASET v1.0 Category: Binary search trees ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node* createNode(int value){
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = value;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

struct node* insertNode(struct node* root, int value){
   if(root == NULL){
      return createNode(value);
   }
   if(value < root->data){
      root->left = insertNode(root->left, value);
   }
   else if(value > root->data){
      root->right = insertNode(root->right, value);
   }
   return root;
}

struct node* searchNode(struct node* root, int value){
   if(root == NULL || root->data == value){
      return root;
   }
   if(value < root->data){
      return searchNode(root->left, value);
   }
   return searchNode(root->right, value);
}

void inorder(struct node* root){
   if(root != NULL){
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
   }
}

int main(){
   struct node *root = NULL;
   int choice, value;
   while(1){
      printf("\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice){
         case 1:
            printf("Insert value: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
         case 2:
            printf("Search value: ");
            scanf("%d", &value);
            if(searchNode(root, value) != NULL){
               printf("Value found\n");
            }
            else{
               printf("Value not found\n");
            }
            break;
         case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
         case 4:
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }
   return 0;
}