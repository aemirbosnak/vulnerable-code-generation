//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void menu(){
    printf("\n-----------Menu------------");
    printf("\n1. Insert a node");
    printf("\n2. Traverse in Inorder");
    printf("\n3. Traverse in Preorder");
    printf("\n4. Traverse in Postorder");
    printf("\n5. Exit");
    printf("\n----------------------------");
}

int main(){
    struct node* root = NULL;
    int choice, val;
    menu();
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("\nInorder traversal: ");
                inOrder(root);
                break;
            case 3:
                printf("\nPreorder traversal: ");
                preOrder(root);
                break;
            case 4:
                printf("\nPostorder traversal: ");
                postOrder(root);
                break;
            case 5:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }
    }while(choice!=5);

    return 0;
}