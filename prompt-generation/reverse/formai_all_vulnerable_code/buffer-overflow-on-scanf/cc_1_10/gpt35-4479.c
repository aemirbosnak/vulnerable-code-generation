//FormAI DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

// Binary Search Tree Node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new BST node
struct node * new_node(int value){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

// Function to insert a new node in a BST
struct node * insert(struct node *root, int value){
    if(root==NULL) return new_node(value);
    if(value < root->data)
        root->left=insert(root->left, value);
    else if(value > root->data)
        root->right=insert(root->right, value);
    return root;
}

// Function to search for a node in a BST
struct node * search(struct node *root, int value){
    if(root==NULL || root->data==value) return root;
    if(value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Function to traverse a BST in InOrder fashion
void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    printf("Welcome to a Cheerful Binary Search Tree example program!\n\n");
    struct node *root=NULL;
    int choice, value, count=0;

    // Menu driven program
    while(1){
        printf("\n1. Insert Element in Binary Search Tree");
        printf("\n2. Search Element in Binary Search Tree");
        printf("\n3. Traverse Binary Search Tree in InOrder");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("\nEnter element to insert: ");
                scanf("%d", &value);
                root=insert(root, value);
                count++;
                break;

            case 2:
                printf("\nEnter element to search: ");
                scanf("%d", &value);
                if(search(root, value))
                    printf("\n%d exists in the Binary Search Tree!\n", value);
                else
                    printf("\n%d does not exist in the Binary Search Tree!\n", value);
                break;

            case 3:
                if(root==NULL){
                    printf("\nBinary Search Tree is Empty!");
                    break;
                }
                printf("\nInOrder Traversal of Binary Search Tree:\n");
                inorder(root);
                break;

            case 4:
                printf("\nThank You for using the program!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again!");
        }
    }
    return 0;
}