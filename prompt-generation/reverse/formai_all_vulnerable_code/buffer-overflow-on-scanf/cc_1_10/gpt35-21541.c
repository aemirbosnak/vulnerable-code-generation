//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

//function to create new node
struct node* createNode(int value){
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode -> data = value;
  newnode -> left = NULL;
  newnode -> right = NULL;
  return newnode;
}

//function to insert node into tree
struct node* insertNode(struct node* root, int value){
  if(root == NULL){
    root = createNode(value);
    return root;
  }
  if(value < root -> data){
    root -> left = insertNode(root -> left, value);
  }
  else{
    root -> right = insertNode(root -> right, value);
  }
  return root;
}

//function to traverse tree and print node values
void inorderTraversal(struct node* root){
  if(root != NULL){
    inorderTraversal(root -> left);
    printf("%d ", root -> data);
    inorderTraversal(root -> right);
  }
}

//function to search for a particular value in the tree
struct node* searchNode(struct node* root, int value){
  if(root == NULL || root -> data == value){
    return root;
  }
  if(root -> data < value){
    return searchNode(root -> right, value);
  }
  return searchNode(root -> left, value);
}

int main(){
  struct node* root = NULL;
  int n;

  //input number of nodes to enter
  printf("Enter number of nodes you want to enter: ");
  scanf("%d", &n);

  //input node values and insert them into the tree
  printf("Enter the values: ");
  int i, val;
  for(i = 0; i < n; i++){
    scanf("%d", &val);
    root = insertNode(root, val);
  }

  //print the values of nodes in the tree
  printf("Values in the tree: ");
  inorderTraversal(root);

  //input value to search for in the tree
  printf("\nEnter the value to search for: ");
  int searchVal;
  scanf("%d", &searchVal);

  //search for the entered value in the tree
  struct node* searchResult = searchNode(root, searchVal);
  if(searchResult == NULL){
    printf("Value not found in the tree.");
  }
  else{
    printf("Value found in the tree.");
  }

  return 0;
}