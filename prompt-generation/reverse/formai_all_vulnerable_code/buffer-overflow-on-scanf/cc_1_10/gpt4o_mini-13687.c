//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int id, const char* name) {
    if (root == NULL) {
        return createNode(id, name);
    }

    if (id < root->id) {
        root->left = insert(root->left, id, name);
    } else if (id > root->id) {
        root->right = insert(root->right, id, name);
    } else {
        printf("Duplicate ID found. Not adding entry.\n");
    }

    return root;
}

Node* search(Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return search(root->left, id);
    }

    return search(root->right, id);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL) {
        return root;
    }

    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("ID: %d, Name: %s\n", root->id, root->name);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, id;
    char name[50];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Insert Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Display All Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                root = insert(root, id, name);
                break;
            case 2:
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                Node* found = search(root, id);
                if (found != NULL) {
                    printf("Found - ID: %d, Name: %s\n", found->id, found->name);
                } else {
                    printf("ID not found.\n");
                }
                break;
            case 3:
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                printf("Entry deleted if it existed.\n");
                break;
            case 4:
                printf("All Entries in the Database:\n");
                inOrderTraversal(root);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}