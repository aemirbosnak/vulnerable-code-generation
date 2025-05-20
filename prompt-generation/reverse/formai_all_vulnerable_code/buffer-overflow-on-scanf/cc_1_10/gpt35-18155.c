//FormAI DATASET v1.0 Category: Binary search trees ; Style: excited
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* NewNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right =  NULL;

    return node;
}

struct Node* Insert(struct Node* root, int data){
    if(root == NULL){
        root = NewNode(data);
        return root;
    }
    else if(data <= root -> data){
        root -> left = Insert(root -> left, data);
    }
    else{
        root -> right = Insert(root -> right, data);
    }

    return root;
}

struct Node* Search(struct Node* root, int data){
    if(root == NULL){
        printf("Sorry, data not found in the Binary Search Tree.\n");
        return NULL;
    }
    else if(root -> data == data){
        printf("Data found in the Binary Search Tree.\n");
        return root;
    }
    else if(data <= root -> data){
        return Search(root -> left, data);
    }
    else{
        return Search(root -> right, data);
    }
}

void InOrderTraversal(struct Node* root){
    if(root == NULL){
        return;
    }
    else{
        InOrderTraversal(root -> left);
        printf("%d ", root -> data);
        InOrderTraversal(root -> right);
    }
}

int main(){
    struct Node* root = NULL;

    root = Insert(root, 5);
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 2);
    root = Insert(root, 3);

    printf("\n\nThe In-Order Traversal of the Binary Search Tree is : ");
    InOrderTraversal(root);

    int data = 0;
    printf("\n\nEnter data to be searched : ");
    scanf("%d", &data);

    struct Node* searchResult = Search(root, data);
    
    if(searchResult != NULL){
        printf("\n\nThe data found in Binary Search Tree is : %d\n", searchResult -> data);
    }
    else{
        printf("\n\nSorry, data not found in Binary Search Tree.\n");
    }

    return 0;
}