//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

//Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//Function to insert data in the tree
struct Node* insertData(struct Node* root, int data){
    if(root==NULL){
        root=createNode(data);
    }
    else if(data<root->data){
        root->left=insertData(root->left, data);
    }
    else{
        root->right=insertData(root->right, data);
    }
    return root;
}

//Function to search data in the tree
struct Node* searchData(struct Node* root, int data){
    if(root==NULL || root->data==data){
        return root;
    }
    else if(data<root->data){
        return searchData(root->left, data);
    }
    else{
        return searchData(root->right, data);
    }
}

//Function to delete data from the tree
struct Node* deleteData(struct Node* root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left=deleteData(root->left, data);
    }
    else if(data>root->data){
        root->right=deleteData(root->right, data);
    }
    else{
        if(root->left==NULL){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp=searchData(root->right, minValue(root->right));
        root->data=temp->data;
        root->right=deleteData(root->right, temp->data);
    }
    return root;
}

//Function to find minimum value in the tree
int minValue(struct Node* root){
    int min=root->data;
    while(root->left!=NULL){
        min=root->left->data;
        root=root->left;
    }
    return min;
}

//Function to print the tree
void printTree(struct Node* root, int space){
    if(root==NULL){
        return;
    }
    space+=10;
    printTree(root->right, space);
    printf("\n");
    for(int i=10; i<space; i++){
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

//Main function
int main(){
    struct Node* root=NULL;
    int choice, data;
    do{
        printf("\n");
        printf("1. Insert Data\n");
        printf("2. Delete Data\n");
        printf("3. Search Data\n");
        printf("4. Print Tree\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root=insertData(root, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root=deleteData(root, data);
                break;
            case 3:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                struct Node* result=searchData(root, data);
                if(result!=NULL){
                    printf("Data found!\n");
                }
                else{
                    printf("Data not found!\n");
                }
                break;
            case 4:
                printf("\n");
                printTree(root, 0);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=5);
    return 0;
}