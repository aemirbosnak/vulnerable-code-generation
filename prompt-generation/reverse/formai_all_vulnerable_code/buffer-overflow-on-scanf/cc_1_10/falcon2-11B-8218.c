//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int n;
    char* file;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Node* temp = insert(root, i);
        printf("Node %d -> %d\n", i, temp->data);
    }

    printf("Enter the name of the database file: ");
    scanf("%s", file);

    FILE* fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Node* temp = root;
        while (temp!= NULL) {
            fprintf(fp, "%d %d\n", temp->data, i);
            temp = temp->left;
        }
    }

    fclose(fp);

    return 0;
}