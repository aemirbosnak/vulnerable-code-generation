//FormAI DATASET v1.0 Category: Binary search trees ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, int val) {
    if (*root == NULL) {
        *root = createNode(val);
        return;
    }
    if (val < (*root)->val) {
        insert(&((*root)->left), val);
    }
    else {
        insert(&((*root)->right), val);
    }
}

Node* search(Node *root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return search(root->left, val);
    }
    else {
        return search(root->right, val);
    }
}

Node* minValNode(Node *node) {
    Node *current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* delete(Node *root, int val) {
    if (root == NULL) {
        return root;
    }
    if (val < root->val) {
        root->left = delete(root->left, val);
    }
    else if (val > root->val) {
        root->right = delete(root->right, val);
    }
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValNode(root->right);
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}

void printInorder(Node *root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, val;
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Print Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(&root, val);
                printf("%d inserted into BST\n", val);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                if (search(root, val) == NULL) {
                    printf("%d is not present in the BST\n", val);
                }
                else {
                    root = delete(root, val);
                    printf("%d deleted from BST\n", val);
                }
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                if (search(root, val) == NULL) {
                    printf("%d is not present in the BST\n", val);
                }
                else {
                    printf("%d is present in the BST\n", val);
                }
                break;
            case 4:
                printf("Inorder Traversal of BST: ");
                printInorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    return 0;
}