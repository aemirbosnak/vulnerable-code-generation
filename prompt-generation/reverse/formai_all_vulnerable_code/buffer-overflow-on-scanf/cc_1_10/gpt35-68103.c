//FormAI DATASET v1.0 Category: Binary search trees ; Style: genious
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
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
        root = createNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    else if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

Node* findMin(Node* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return findMin(root->left);
    }
}

Node* delete(Node* root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    Node* root = NULL;

    printf("Welcome to the Binary Search Tree Example Program!\n\n");

    printf("Enter data to insert into the tree (-1 to exit): ");
    int data;
    scanf("%d", &data);
    while(data != -1){
        root = insert(root, data);
        printf("Enter data to insert into the tree (-1 to exit): ");
        scanf("%d", &data);
    }

    printf("\nInorder Traversal of the Tree: ");
    inorder(root);

    printf("\n\nEnter data to search in the tree (-1 to exit): ");
    int searchData;
    scanf("%d", &searchData);
    while(searchData != -1){
        Node* searchResult = search(root, searchData);
        if(searchResult == NULL){
            printf("%d not found in the tree.\n", searchData);
        }
        else{
            printf("%d found in the tree.\n", searchData);
        }
        printf("Enter data to search in the tree (-1 to exit): ");
        scanf("%d", &searchData);
    }

    printf("\n\nEnter data to delete from the tree (-1 to exit): ");
    int deleteData;
    scanf("%d", &deleteData);
    while(deleteData != -1){
        root = delete(root, deleteData);
        printf("Inorder Traversal of the Tree after deleting %d: ", deleteData);
        inorder(root);
        printf("\nEnter data to delete from the tree (-1 to exit): ");
        scanf("%d", &deleteData);
    }

    return 0;
}