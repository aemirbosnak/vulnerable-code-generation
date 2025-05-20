//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* node, int data){
    if(node==NULL){
        return create_node(data);
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

struct node* search(struct node* root, int data){
    if(root==NULL || root->data==data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

void in_order(struct node* node){
    if(node!=NULL){
        in_order(node->left);
        printf("%d ", node->data);
        in_order(node->right);
    }
}

int main(){
    struct node* root = NULL;
    int n, data;
    printf("Enter the number of elements in the binary search tree:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("In-order traversal of the binary search tree:\n");
    in_order(root);
    printf("\nEnter the element to be searched:\n");
    scanf("%d", &data);
    struct node* result = search(root, data);
    if(result==NULL){
        printf("Element not found\n");
    }
    else{
        printf("Element found\n");
    }
    return 0;
}