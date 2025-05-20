//FormAI DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node* search(Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main(){
    Node* root = NULL;
    int choice, data, searchKey;
    while(1){
        printf("\n1. Insert Node");
        printf("\n2. Inorder Traversal");
        printf("\n3. Search for a Node");
        printf("\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Element to Insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Enter Element to Search: ");
                scanf("%d", &searchKey);
                Node* searchResult = search(root, searchKey);
                if(searchResult == NULL){
                    printf("Node not Found!\n");
                }
                else{
                    printf("Node Found!\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}