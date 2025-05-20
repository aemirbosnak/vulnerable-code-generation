//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to create a node for linked list
struct node {
   int data;
   struct node *next;
};

//Function to create a stack node
struct stack_node {
   char data;
   struct stack_node *next;
};

//Function to create a new node for binary tree
struct tree_node {
   char data;
   struct tree_node *left;
   struct tree_node *right;
};

void display_linked_list(struct node *node) {
   while(node!=NULL) {
      printf("%d->",node->data);
      node=node->next;
   }
   printf("NULL\n");
}

void display_stack(struct stack_node *node) {
   while(node!=NULL) {
      printf("%c\n",node->data);
      node=node->next;
   }
}

void display_tree(struct tree_node *root, int space) {
   if (root == NULL) 
      return;
   space += 10;
   display_tree(root->right, space);
   printf("\n");
   for (int i = 10; i < space; i++)
      printf(" ");
   printf("%c \n", root->data);
   display_tree(root->left, space);
}

int main() {
   printf("Welcome to the data structures visualization program!\n\n");
   
   printf("Let's start by creating a singly linked list...\n\n");
   //Creating a linked list
   struct node *head=NULL, *second=NULL, *third=NULL;
   head=(struct node*)malloc(sizeof(struct node));
   second=(struct node*)malloc(sizeof(struct node));
   third=(struct node*)malloc(sizeof(struct node));
   
   head->data=1;
   head->next=second;
   
   second->data=2;
   second->next=third;
   
   third->data=3;
   third->next=NULL;
   
   printf("Linked List: ");
   display_linked_list(head);

   printf("\nGreat! Let's move on to creating a stack...\n\n");
   //Creating a stack
   struct stack_node *top=NULL;
   char s[100];
   printf("Enter a string to push onto the stack: ");
   scanf("%s", s);
   int len=strlen(s);
   for(int i=0;i<len;i++) {
      struct stack_node *new_node=NULL;
      new_node=(struct stack_node*)malloc(sizeof(struct stack_node));
      new_node->data=s[i];
      new_node->next=top;
      top=new_node;
   }
   printf("\nStack: \n");
   display_stack(top);
  
   printf("\nGreat! Let's move on to creating a binary tree...\n\n");
   //Creating a binary tree
   struct tree_node *root=NULL, *left_child=NULL, *right_child=NULL, *right_left_child=NULL, *right_right_child=NULL;
   root=(struct tree_node*)malloc(sizeof(struct tree_node));
   left_child=(struct tree_node*)malloc(sizeof(struct tree_node));
   right_child=(struct tree_node*)malloc(sizeof(struct tree_node));
   right_left_child=(struct tree_node*)malloc(sizeof(struct tree_node));
   right_right_child=(struct tree_node*)malloc(sizeof(struct tree_node));
   
   root->data='A';
   root->left=left_child;
   root->right=right_child;
   
   left_child->data='B';
   left_child->left=NULL;
   left_child->right=NULL;
   
   right_child->data='C';
   right_child->left=right_left_child;
   right_child->right=right_right_child;
   
   right_left_child->data='D';
   right_left_child->left=NULL;
   right_left_child->right=NULL;
   
   right_right_child->data='E';
   right_right_child->left=NULL;
   right_right_child->right=NULL;
   
   printf("Binary Tree: \n");
   display_tree(root,0);
   
   printf("\nThat's it for the data structure visualization program! Thank you for using it.\n\n");
   return 0;
}