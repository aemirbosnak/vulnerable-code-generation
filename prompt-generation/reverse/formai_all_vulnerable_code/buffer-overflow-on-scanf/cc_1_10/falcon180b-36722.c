//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    char name[MAX];
    int age;
    int height;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(char name[], int age, int height) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->height = height;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, char name[], int age, int height) {
    if (root == NULL) {
        root = newNode(name, age, height);
    } else if (strcmp(root->name, name) > 0) {
        root->left = insert(root->left, name, age, height);
    } else if (strcmp(root->name, name) < 0) {
        root->right = insert(root->right, name, age, height);
    }
    return root;
}

Node* search(Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    } else if (strcmp(root->name, name) > 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

void inorder(Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%s %d %d\n", root->name, root->age, root->height);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    char name[MAX];
    int age, height;

    printf("Enter name, age and height of a person (or type'search' to search for a person):\n");
    while (scanf("%s %d %d", name, &age, &height) == 3) {
        if (strcmp(name, "search") == 0) {
            printf("Enter name to search for:\n");
            scanf("%s", name);
            Node* result = search(root, name);
            if (result!= NULL) {
                printf("Found %s, age %d, height %d\n", result->name, result->age, result->height);
            } else {
                printf("Not found\n");
            }
        } else {
            root = insert(root, name, age, height);
        }
        printf("Enter another person (or type 'inorder' to print the tree in order):\n");
    }

    if (strcmp(name, "inorder") == 0) {
        inorder(root);
    }

    return 0;
}