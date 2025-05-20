//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int id;
    char name[50];
    struct Record *left;
    struct Record *right;
} Record;

Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, 50);
    newRecord->left = NULL;
    newRecord->right = NULL;
    return newRecord;
}

Record* insertRecord(Record* root, int id, const char* name) {
    if (root == NULL) {
        return createRecord(id, name);
    }
    if (id < root->id) {
        root->left = insertRecord(root->left, id, name);
    } else if (id > root->id) {
        root->right = insertRecord(root->right, id, name);
    }
    return root;
}

Record* searchRecord(Record* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return searchRecord(root->left, id);
    }
    return searchRecord(root->right, id);
}

Record* findMin(Record* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Record* deleteRecord(Record* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->id) {
        root->left = deleteRecord(root->left, id);
    } else if (id > root->id) {
        root->right = deleteRecord(root->right, id);
    } else {
        if (root->left == NULL) {
            Record* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Record* temp = root->left;
            free(root);
            return temp;
        }
        Record* temp = findMin(root->right);
        root->id = temp->id;
        strncpy(root->name, temp->name, 50);
        root->right = deleteRecord(root->right, temp->id);
    }
    return root;
}

void inOrderTraversal(Record* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("ID: %d, Name: %s\n", root->id, root->name);
    inOrderTraversal(root->right);
}

void freeTree(Record* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Record* root = NULL;
    int choice, id;
    char name[50];

    while (1) {
        printf("Database Indexing System\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                root = insertRecord(root, id, name);
                printf("Record inserted.\n");
                break;
            case 2:
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                Record* foundRecord = searchRecord(root, id);
                if (foundRecord) {
                    printf("Record Found - ID: %d, Name: %s\n", foundRecord->id, foundRecord->name);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                root = deleteRecord(root, id);
                printf("Record deleted if it existed.\n");
                break;
            case 4:
                printf("Records in Database:\n");
                inOrderTraversal(root);
                break;
            case 5:
                freeTree(root);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}