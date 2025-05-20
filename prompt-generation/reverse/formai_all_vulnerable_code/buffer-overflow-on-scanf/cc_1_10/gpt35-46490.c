//FormAI DATASET v1.0 Category: Binary search trees ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create_node(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
        return root;
    }
    else {
        root->right = insert(root->right, data);
        return root;
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

Node* search(Node* root, int data) {
    if (root == NULL) {
        printf("%d not found in the tree.\n", data);
        return NULL;
    }
    else if (root->data == data) {
        printf("%d found in the tree.\n", data);
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int data) {
    if (root == NULL) {
        printf("%d not found in the tree.\n", data);
        return root;
    }
    else if (data < root->data) {
        root->left = delete(root->left, data);
        return root;
    }
    else if (data > root->data) {
        root->right = delete(root->right, data);
        return root;
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            return root;
        }
    }
}

int main() {
    Node* root = NULL;
    printf("Enter the number of elements to insert: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements to insert: ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        root = insert(root, num);
    }
    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");
    printf("Enter the number of elements to search: ");
    int s;
    scanf("%d", &s);
    printf("Enter the elements to search: ");
    for (int i = 0; i < s; i++) {
        int num;
        scanf("%d", &num);
        search(root, num);
    }
    printf("Enter the number of elements to delete: ");
    int d;
    scanf("%d", &d);
    printf("Enter the elements to delete: ");
    for (int i = 0; i < d; i++) {
        int num;
        scanf("%d", &num);
        root = delete(root, num);
    }
    printf("Inorder traversal of the tree after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}