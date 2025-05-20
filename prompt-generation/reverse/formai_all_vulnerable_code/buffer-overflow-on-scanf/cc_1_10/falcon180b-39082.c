//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->index = -1;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        Node* currNode = *root;
        while (currNode->index!= -1) {
            currNode = currNode->index;
        }
        currNode->index = createNode(data)->index;
    }
}

int search(Node* root, int data) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == data) {
        return root->index;
    }
    int currIndex = root->index;
    while (currIndex!= -1) {
        root = root->index;
        if (root->data == data) {
            return root->index;
        }
        currIndex = root->index;
    }
    return -1;
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            int result = search(root, data);
            if (result == -1) {
                printf("Element not found\n");
            } else {
                printf("Element found at index %d\n", result);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}