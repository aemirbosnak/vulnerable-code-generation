//FormAI DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

/* Define the node structure for BST */
struct node {
    int data;
    struct node *left, *right;
};

/* Function to create a new 
node with given data */
struct node* newNode(int data) {
    struct node* temp 
            = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Function to insert a new node in BST */
struct node* insert(struct node* node, int data) {
    if (node == NULL) 
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

/* Function to search for a node 
with given key value in BST */
struct node* search(struct node* root, int key) {
    // Return NULL if root is NULL or the key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's data
    if (root->data < key) 
        return search(root->right, key);

    // Key is smaller than root's data
    return search(root->left, key);
}

/* Function to traverse the nodes in BST using inorder traversal */
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Main function to test the BST operations */
int main() {
    struct node* root = NULL;
    int key, value;
    int choice = 1;

    printf("\n************ Welcome to BST insertion and search **************");

    while (choice != 0) {
        printf("\nChoose an operation:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Traverse the BST\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted successfully!\n");
                break;
            case 2:
                printf("Enter the key value to search: ");
                scanf("%d", &key);
                if (search(root, key) == NULL)
                    printf("Key not found in BST!\n");
                else
                    printf("Key found in BST!\n");
                break;
            case 3:
                inorder(root);
                break;
            case 0:
                printf("Exiting the program.....\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}