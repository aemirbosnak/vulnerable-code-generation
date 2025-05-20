//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

// Structure to represent BST node
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create new BST node
struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert new node in BST
struct node* insertNode(struct node* root, int value)
{
    if(root == NULL) // If the tree is empty
        return createNode(value);
    if(value < root->data) // If the key is smaller than root's key
        root->left = insertNode(root->left, value);
    else if(value > root->data) // If the key is greater than root's key
        root->right = insertNode(root->right, value);
    return root;
}

// Function to search for a node in BST
struct node* searchNode(struct node* root, int value)
{
    if(root == NULL || root->data == value)
        return root;
    if(value < root->data) // If the key is smaller than root's key
        return searchNode(root->left, value);
    else // If the key is greater than root's key
        return searchNode(root->right, value);
}

// Function to find minimum value in a BST
struct node* findMin(struct node* node)
{
    while(node->left != NULL)
        node = node->left;
    return node;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int value)
{
    if(root == NULL)
        return root;
    if(value < root->data) // If the key is smaller than root's key
        root->left = deleteNode(root->left, value);
    else if(value > root->data) // If the key is greater than root's key
        root->right = deleteNode(root->right, value);
    else // If key is same as root's key
    {
        if(root->left == NULL) // If node has only right child or no child
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) // If node has only left child
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // If node has two children, find in-order successor
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the BST in inorder traversal
void inorderTraversal(struct node* root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main program
int main()
{
    struct node* root = NULL; // initialize the root node
    int choice; // To choose from menu
    int value; // For new node value
    while(1) // Run the loop till user exit 
    {
        printf("\n\n\t\t----- Welcome to Binary Search Tree Program -----\n\n\n");
        printf("\t\t\tMENU\n");
        printf("\t\t1. Insert Node\n");
        printf("\t\t2. Search Node\n");
        printf("\t\t3. Delete Node\n");
        printf("\t\t4. Print BST in Inorder Traversal\n");
        printf("\t\t5. Exit\n");
        printf("\t\tEnter your choice: ");
        scanf("%d", &choice); // Read user input
        switch(choice)
        {
            case 1:
                printf("\nEnter the value of new node: ");
                scanf("%d", &value);
                root = insertNode(root, value); // insert the new node
                printf("\nNode Added Successfully!");
                break;
            case 2:
                printf("\nEnter the value of node to be searched: ");
                scanf("%d", &value);
                if(searchNode(root, value) != NULL) // If node is found
                    printf("\nNode Found!");
                else // If node is not found
                    printf("\nNode Not Found!");
                break;
            case 3:
                printf("\nEnter the value of node to be deleted: ");
                scanf("%d", &value);
                if(searchNode(root, value) == NULL) // If node is not found
                {
                    printf("\nNode Not Found!");
                    break;
                }
                root = deleteNode(root, value); // Delete the node
                printf("\nNode Deleted Successfully!");
                break;
            case 4:
                printf("\nInorder Traversal of BST: ");
                inorderTraversal(root); // Print BST in inorder traversal
                break;
            case 5:
                printf("\n\nExiting Program!..\n");
                exit(0); // Exit the program
            default:
                printf("\n\nInvalid Choice! Please Try Again..");
        }
    }
    return 0;
}