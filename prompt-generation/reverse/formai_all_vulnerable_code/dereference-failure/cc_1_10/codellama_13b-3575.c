//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: complete
/*
 * Program to visualize various data structures in C
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void push(Node **head_ref, int data) {
    Node *new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print a linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Structure to represent a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* newTreeNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in a binary tree
void insert(TreeNode **root, int data) {
    TreeNode *new_node = newTreeNode(data);
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    TreeNode *curr = *root;
    while (curr != NULL) {
        if (curr->data < data) {
            if (curr->right == NULL) {
                curr->right = new_node;
                return;
            }
            curr = curr->right;
        } else {
            if (curr->left == NULL) {
                curr->left = new_node;
                return;
            }
            curr = curr->left;
        }
    }
}

// Function to print a binary tree
void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    // Linked list example
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printList(head);

    // Binary tree example
    TreeNode *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    printTree(root);

    return 0;
}