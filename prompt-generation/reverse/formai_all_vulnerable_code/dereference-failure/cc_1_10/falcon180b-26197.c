//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

//Define structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        root = newNode(value);
        return root;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

//Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (root->data < value)
        return search(root->right, value);

    return search(root->left, value);
}

//Function to print the BST in order traversal
void printOrder(struct Node* root) {
    if (root == NULL)
        return;

    printOrder(root->left);
    printf("%d ", root->data);
    printOrder(root->right);
}

//Function to print the BST in preorder traversal
void printPreOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//Function to print the BST in postorder traversal
void printPostOrder(struct Node* root) {
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

//Main function
int main() {
    struct Node* root = NULL;

    //Insert values into the BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    //Print BST in order traversal
    printf("Order traversal: ");
    printOrder(root);
    printf("\n");

    //Print BST in preorder traversal
    printf("Preorder traversal: ");
    printPreOrder(root);
    printf("\n");

    //Print BST in postorder traversal
    printf("Postorder traversal: ");
    printPostOrder(root);
    printf("\n");

    //Search for a value in the BST
    struct Node* searchResult = search(root, 30);
    if (searchResult!= NULL)
        printf("Value found!\n");
    else
        printf("Value not found.\n");

    return 0;
}