//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data){
    
    if(root == NULL){
        root = createNode(data);
    }else if(data <= root->data){
        root->left = insert(root->left, data);
    }else {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(struct node* root, int data){
    if(root == NULL){
        return 0;
    }else if(root->data == data){
        return 1;
    }else if(data <= root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

int main(){

    struct node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 20);

    int num;
    printf("Enter number to be searched: ");
    scanf("%d", &num);

    if(search(root, num)){
        printf("Found!\n");
    }else{
        printf("Not found!\n");
    }

    return 0;
}