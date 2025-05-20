//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// structure for a node in the BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function to create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a node
struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// function to search for a node
struct node *search(struct node *root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// function to find the minimum value in a BST
struct node *findMin(struct node *root) {
    if(root == NULL) {
        return root;
    }
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

// function to delete a node from a BST
struct node *delete(struct node *root, int data) {
    if(root == NULL) {
        return root;
    }
    if(data < root->data) {
        root->left = delete(root->left, data);
    }
    else if(data > root->data) {
        root->right = delete(root->right, data);
    }
    else {
        // node with only one child or no child
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// function to traverse the BST and print out the nodes in ascending order
void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, value;
    
    // loop to get user inputs and perform operations on the BST
    do {
        printf("\nBinary Search Tree Operations\n");
        printf("-------------------------------\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Traverse the BST\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
                
            case 2:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
                
            case 3:
                printf("\nEnter the value to be searched: ");
                scanf("%d", &value);
                if(search(root, value) != NULL) {
                    printf("%d is present in the BST.", value);
                }
                else {
                    printf("%d is not present in the BST.", value);
                }
                break;
            
            case 4:
                printf("\nThe BST in ascending order is: ");
                inorderTraversal(root);
                break;
                
            case 5:
                printf("\nExiting...\n");
                exit(0);
                break;
            
            default:
                printf("\nInvalid choice! Try again.");
        }
        
    } while(choice != 5);
    
    return 0;
}