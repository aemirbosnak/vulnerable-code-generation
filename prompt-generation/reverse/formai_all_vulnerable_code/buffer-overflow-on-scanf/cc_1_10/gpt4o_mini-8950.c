//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function for Insertion
struct Node *insert(struct Node *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to search for a value
struct Node *search(struct Node *node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return search(node->left, data);
    }
    return search(node->right, data);
}

// Function for deleting a node
struct Node *deleteNode(struct Node *node, int data) {
    if (node == NULL) {
        return node;
    }
    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (node->left == NULL) {
            struct Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        struct Node *temp = node->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// Function for Inorder Traversal
void inorderTraversal(struct Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Function to display the tree
void display(struct Node *node, int space) {
    if (node == NULL) {
        return;
    }
    space += 10;
    display(node->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);
    display(node->left, space);
}

// The mysterious main function
int main() {
    struct Node *root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Display the tree\n");
        printf("6. Exit\n");
        printf("Choose an operation (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node *foundNode = search(root, value);
                if (foundNode) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted successfully.\n", value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Current tree structure:\n");
                display(root, 0);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}