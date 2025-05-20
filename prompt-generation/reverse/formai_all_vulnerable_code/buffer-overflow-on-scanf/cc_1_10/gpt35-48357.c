//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
// Welcome to the Database Indexing System!

#include <stdio.h>
#include <stdlib.h>

struct record {
    int id;
    char name[50];
    float score;
};

struct node {
    struct record data;
    struct node* left;
    struct node* right;
};

struct node* create_node(struct record r) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = r;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, struct record r) {
    if (root == NULL) {
        root = create_node(r);
    }
    else if (r.id < root->data.id) {
        root->left = insert_node(root->left, r);
    }
    else if (r.id > root->data.id) {
        root->right = insert_node(root->right, r);
    }
    return root;
}

struct node* search_node(struct node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    else if (root->data.id > id) {
        return search_node(root->left, id);
    }
    else {
        return search_node(root->right, id);
    }
}

void print_node(struct record r) {
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("Score: %.2f\n", r.score);
}

void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        print_node(root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, id;
    struct record r;
    
    printf("Welcome to the Database Indexing System!\n\n");
    
    do {
        printf("\nMENU\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &r.id);
                printf("Enter Name: ");
                scanf("%s", r.name);
                printf("Enter Score: ");
                scanf("%f", &r.score);
                root = insert_node(root, r);
                printf("\nRecord Added!\n");
                break;
            case 2:
                printf("\nEnter ID to search: ");
                scanf("%d", &id);
                struct node* result = search_node(root, id);
                if (result == NULL) {
                    printf("\nRecord not found!\n");
                }
                else {
                    printf("\nRecord found!\n");
                    print_node(result->data);
                }
                break;
            case 3:
                printf("\nRecords:\n");
                inorder_traversal(root);
                break;
            case 4:
                printf("\nExiting Database Indexing System. Bye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}