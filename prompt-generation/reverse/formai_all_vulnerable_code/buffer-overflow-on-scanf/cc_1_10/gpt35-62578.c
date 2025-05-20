//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for each node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node for the binary search tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
Node* search(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == data) {
        return root;
    }
    else if (root->data > data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Function to print the binary search tree in order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Main function to create and test the binary search tree
int main() {

    printf("Welcome to the Medieval Binary Search Tree Village!\n");
    printf("Enter the integer values of the villagers to add them into the binary search tree:\n");
    
    Node* root = NULL;
    int numVillagers;
    printf("Number of villagers: ");
    scanf("%d", &numVillagers);

    for (int i = 0; i < numVillagers; i++) {
        int data;
        printf("Villager %d: ", i+1);
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("\n");

    printf("Here is a list of the villagers in ascending order:\n");
    printInOrder(root);
    printf("\n");

    int searchValue;
    printf("Enter a value to search for in the village: ");
    scanf("%d", &searchValue);

    Node* result = search(root, searchValue);
    if (result == NULL) {
        printf("The villager was not found in the village.\n");
    }
    else {
        printf("The villager was found in the village.\n");
    }

    return 0;
}