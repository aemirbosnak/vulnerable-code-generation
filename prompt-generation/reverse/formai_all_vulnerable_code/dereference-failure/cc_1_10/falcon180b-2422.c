//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node* root, int data){
    if(root==NULL){
        root = createNode(data);
        return root;
    }
    if(data<root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data>root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

node* searchNode(node* root, int data){
    if(root==NULL || root->data==data){
        return root;
    }
    if(data<root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}

node* minValueNode(node* root){
    node* current = root;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}

node* deleteNode(node* root, int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data>root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    node* search = searchNode(root, 40);
    if(search!=NULL){
        printf("\nNode with data 40 found");
    }
    else{
        printf("\nNode with data 40 not found");
    }
    root = deleteNode(root, 20);
    printf("\nAfter deleting node with data 20: ");
    inorder(root);
    return 0;
}