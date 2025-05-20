//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void displayMenu() {
    printf("\nMultiplayer Binary Search Tree Menu:\n");
    printf("1. Insert a new number\n");
    printf("2. Search for a number\n");
    printf("3. Display tree (Inorder)\n");
    printf("4. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice, number, playerID;

    printf("Welcome to the Multiplayer Binary Search Tree Game!\n");
    
    while (1) {
        displayMenu();
        printf("Player, enter your ID (1 or 2): ");
        scanf("%d", &playerID);
        
        if (playerID != 1 && playerID != 2) {
            printf("Invalid player ID! Please enter 1 or 2.\n");
            continue;
        }

        printf("Choose an action (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Player %d, enter a number to insert: ", playerID);
                scanf("%d", &number);
                root = insert(root, number);
                printf("Player %d inserted %d.\n", playerID, number);
                break;
            case 2:
                printf("Player %d, enter a number to search: ", playerID);
                scanf("%d", &number);
                if (search(root, number))
                    printf("Player %d, %d found in the tree!\n", playerID, number);
                else
                    printf("Player %d, %d not found in the tree!\n", playerID, number);
                break;
            case 3:
                printf("Current tree (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the game. Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1-4.\n");
        }

        printf("Current state of the tree (Inorder): ");
        inorder(root);
        printf("\n");
    }

    return 0;
}