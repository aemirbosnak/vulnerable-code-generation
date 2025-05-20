//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#define MAX 100  //maximum number of nodes

//structure for binary search tree node
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

//function to insert a node in binary search tree
Node *insert(Node *root, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root==NULL){
        root = newNode;
        return root;
    }

    Node *temp = root;
    while(temp!=NULL){
        if(value < temp->data){
            if(temp->left==NULL){
                temp->left = newNode;
                return root;
            }
            temp = temp->left;
        }
        else{
            if(temp->right==NULL){
                temp->right = newNode;
                return root;
            }
            temp = temp->right;
        }
    }
}

//function to search a node in binary search tree
int search(Node *root, int value){
    Node *temp = root;
    while(temp!=NULL){
        if(temp->data==value)
            return 1;
        else if(value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return 0;
}

//function to print binary search tree in in-order traversal
void printInOrder(Node *root){
    if(root==NULL)
        return;

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

//main function
int main(){
    Node *root = NULL;
    long int input;
    printf("Welcome to curious Binary Search Tree implemented in C!\n");
    printf("Enter the number of nodes to insert in the tree: ");
    scanf("%ld", &input);

    if(input<=0){
        printf("Invalid input. Exiting the program!");
        return 0;
    }
    else if(input>MAX){
        printf("Maximum number of nodes allowed is %d. Adjusting input to %d\n", MAX, MAX);
        input = MAX;
    }
    else{
        printf("Valid input detected. Generating %ld random nodes to insert in the tree.\n", input); 
    }

    //inserting random nodes in binary search tree
    for(long int i=1;i<=input;i++){
        int value = rand()%MAX + 1;
        root = insert(root, value);
    }

    printf("\nIn-order traversal of binary search tree after inserting %ld nodes: \n", input);
    printInOrder(root);

    //searching for a node in the binary search tree
    printf("\n\nEnter the value to search in the binary search tree: ");
    int value;
    scanf("%d", &value);
    if(search(root, value))
        printf("%d exists in the binary search tree.", value);
    else
        printf("%d does not exist in the binary search tree.", value);

    return 0;
}