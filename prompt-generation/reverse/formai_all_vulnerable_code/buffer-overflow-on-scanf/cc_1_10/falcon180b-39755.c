//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }
    if(data < root->data) {
        root->child = insertNode(root->child, data);
    }
    else if(data > root->data) {
        root->next = insertNode(root->next, data);
    }
    else {
        printf("Duplicate data\n");
    }
    return root;
}

void search(struct Node* root, int data) {
    if(root == NULL) {
        printf("Not found\n");
        return;
    }
    if(data < root->data) {
        search(root->child, data);
    }
    else if(data > root->data) {
        search(root->next, data);
    }
    else {
        printf("Found\n");
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    while(true) {
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            root = insertNode(root, data);
        }
        else if(choice == 2) {
            printf("Enter data: ");
            scanf("%d", &data);
            search(root, data);
        }
        else if(choice == 3) {
            exit(0);
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}