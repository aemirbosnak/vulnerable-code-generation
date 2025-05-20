//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure of the Binary Search Tree
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with a given key
Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key in the tree
Node* insert(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
    
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    // Return the (unchanged) node pointer
    return node;
}

// Function to perform inorder traversal of the tree
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to search a key in the tree
Node* search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Driver code to demonstrate the medieval Binary Search Tree
int main() {
    Node* root = NULL;
    int choice, key;
    
    while (1) {
        printf("\nWelcome to the Kingdom of Binary Trees!\n");
        printf("1. Insert a Knight (Node)\n");
        printf("2. Search for a Knight (Node)\n");
        printf("3. Show all Knights (Inorder Traversal)\n");
        printf("4. Exit the Kingdom\n");
        printf("Choose thy option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the power of the Knight (Node value) to be added: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("A brave Knight with power %d has joined the kingdom!\n", key);
                break;

            case 2:
                printf("Enter the power of the Knight (Node value) to search: ");
                scanf("%d", &key);
                Node* foundNode = search(root, key);
                if (foundNode != NULL)
                    printf("Found the Knight with power %d!\n", key);
                else
                    printf("Alas! No Knight with power %d could be found.\n", key);
                break;

            case 3:
                printf("The Knights of the realm are as follows:\n");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Farewell, brave soul! Until next time in the realm of Binary Trees.\n");
                exit(0);
                break;

            default:
                printf("That option does not exist in our kingdom! Please choose wisely.\n");
                break;
        }
    }

    return 0;
}