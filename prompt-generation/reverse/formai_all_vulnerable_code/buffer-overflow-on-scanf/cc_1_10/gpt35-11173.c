//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include<stdio.h>
#include<stdlib.h>
// Node definition
struct node{
    int data;
    struct node* left;
    struct node* right;
};
// Function to create a new node
struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
// Function to insert a new node into BST
struct node* insert(struct node* node, int data){
    if(node == NULL) return newNode(data);
    if(data < node->data) node->left = insert(node->left, data);
    else if(data > node->data) node->right = insert(node->right, data);
    return node;
}
// Function to search for a node in BST
struct node* search(struct node* root, int data){
    if(root == NULL || root->data == data) return root;
    if(root->data < data) return search(root->right, data);
    return search(root->left, data);
}
// Function to traverse BST in-order
void inOrder(struct node* node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}
// Main function
int main(){
    printf("Welcome to Binary Search Tree! Let's add some nodes!\n");
    struct node* root = NULL;
    int choice, data;
    while(1){
        printf("Enter 1 to insert a node, 2 to search for a node, 3 to traverse in-order or 4 to exit.\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node added successfully!\n");
                break;
            case 2:
                printf("Enter the data to search for: ");
                scanf("%d", &data);
                if(search(root, data) != NULL) printf("Node found!\n");
                else printf("Node not found!\n");
                break;
            case 3:
                printf("In-order traversal of the tree: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}