//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// structure of Binary Search Tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node of Binary Search Tree
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to insert a node in Binary Search Tree
struct node* insert(struct node* root, int data) {
    // if tree is empty, create a new node
    if (root == NULL) {
        return create_node(data);
    }
    // if data is less than root data, insert it in left subtree
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // if data is greater than root data, insert it in right subtree
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// function to search a node in Binary Search Tree
struct node* search(struct node* root, int data) {
    // if tree is empty or data is found
    if (root == NULL || root->data == data) {
        return root;
    }
    // if data is less than root data, search in left subtree
    else if (data < root->data) {
        return search(root->left, data);
    }
    // if data is greater than root data, search in right subtree
    else {
        return search(root->right, data);
    }
}

// function to find minimum value node in Binary Search Tree
struct node* find_min_node(struct node* root) {
    struct node* current = root;
    // loop down to find leftmost leaf node (minimum value node)
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// function to delete a node from Binary Search Tree
struct node* delete(struct node* root, int data) {
    // if data is not found
    if (root == NULL) {
        return root;
    }
    // if data is less than root data, delete it from left subtree
    else if (data < root->data) {
        root->left = delete(root->left, data);
    }
    // if data is greater than root data, delete it from right subtree
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    // if data is found
    else {
        // if node has only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // if node has two children
        else {
            struct node* temp = find_min_node(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// function to traverse Binary Search Tree in inorder
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int option, data;
    printf("Choose an option:\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Search a node\n");
    printf("4. Traverse the tree in inorder\n");
    printf("5. Exit\n");
    // loop until user chooses to exit
    while (1) {
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct node* node = search(root, data);
                if (node == NULL) {
                    printf("Node not found\n");
                }
                else {
                    printf("Node found\n");
                }
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}