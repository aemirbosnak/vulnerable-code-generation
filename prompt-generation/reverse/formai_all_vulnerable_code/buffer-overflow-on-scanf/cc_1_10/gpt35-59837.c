//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* findMinimum(Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMinimum(root->left);
    return root;
}

Node* delete(Node* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else {
            Node* temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int option, element;
    do {
        printf("\n\nBinary Search Tree Operations Menu:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &element);
                root = insert(root, element);
                inorder(root);
                break;
            case 2:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &element);
                root = delete(root, element);
                inorder(root);
                break;
            case 3:
                printf("\nEnter the element to be searched: ");
                scanf("%d", &element);
                if (search(root, element) != NULL)
                    printf("\n%d is present in the tree.", element);
                else
                    printf("\n%d is not present in the tree.", element);
                break;
            case 4:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
            case 5:
                printf("\nExiting...");
                exit(0);
                break;
            default:
                printf("\nInvalid option. Try again.");
        }
    } while(option != 5);
    return 0;
}