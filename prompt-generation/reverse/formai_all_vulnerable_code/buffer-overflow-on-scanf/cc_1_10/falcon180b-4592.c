//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert a new node with given data into the BST
struct node* insert(struct node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to print the BST inorder traversal
void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//Main function
int main(){
    struct node* root = NULL;
    int choice, data;

    //Loop to perform operations on BST
    while(1){
        printf("\nEnter your choice:\n1. Insert\n2. Inorder traversal\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal of BST:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}