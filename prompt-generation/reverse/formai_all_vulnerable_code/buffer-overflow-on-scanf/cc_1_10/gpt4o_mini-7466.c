//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A cheerful node structure for our Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Oh no! Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    printf("Yay! Created a new node with value: %d\n", value);
    return newNode;
}

// Function to insert a new value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } 
    if (value < root->data) {
        printf("Going left from %d\n", root->data);
        root->left = insert(root->left, value);
    } else {
        printf("Going right from %d\n", root->data);
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } 
    return search(root->right, value);
}

// Function to find the minimum value in a tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Whoops! Value %d not found!\n", value);
        return root;
    }
    if (value < root->data) {
        printf("Looking for %d on the left side of %d\n", value, root->data);
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        printf("Looking for %d on the right side of %d\n", value, root->data);
        root->right = deleteNode(root->right, value);
    } else {
        printf("Found %d! Let's delete it!\n", value);

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Driver function to demonstrate the BST
int main() {
    struct Node* root = NULL;
    int option, value;

    printf("🎉 Welcome to the cheerful Binary Search Tree program! 🎉\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Insert a new value\n");
        printf("2. Search for a value\n");
        printf("3. Delete a value\n");
        printf("4. In-Order Traversal\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode) {
                    printf("Hooray! The value %d is found in the tree!\n", value);
                } else {
                    printf("Oh no! The value %d is not in the tree!\n", value);
                }
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("In-Order Traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting... Bye-bye! 👋\n");
                break;
            default:
                printf("Oops! Please choose a valid option!\n");
        }
    } while (option != 5);

    return 0;
}