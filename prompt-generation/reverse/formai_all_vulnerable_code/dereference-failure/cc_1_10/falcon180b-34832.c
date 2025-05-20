//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
} Person;

typedef struct Node {
    Person data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, Person data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if ((*root)->data.age > data.age) {
        insert(&(*root)->left, data);
    } else if ((*root)->data.age < data.age) {
        insert(&(*root)->right, data);
    }
}

Node *search(Node *root, Person data) {
    if (root == NULL || root->data.age == data.age) {
        return root;
    } else if (root->data.age < data.age) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

void inorder(Node *root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%s %d years old and %d cm tall\n", root->data.name, root->data.age, root->data.height);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root!= NULL) {
        printf("%s %d years old and %d cm tall\n", root->data.name, root->data.age, root->data.height);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root!= NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s %d years old and %d cm tall\n", root->data.name, root->data.age, root->data.height);
    }
}

int main() {
    Node *root = NULL;
    Person data;
    int choice;

    do {
        printf("Enter the name: ");
        scanf("%s", data.name);
        printf("Enter the age: ");
        scanf("%d", &data.age);
        printf("Enter the height: ");
        scanf("%d", &data.height);
        insert(&root, data);
        printf("1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Search\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                printf("Enter the name to search: ");
                scanf("%s", data.name);
                Node *result = search(root, data);
                if (result == NULL) {
                    printf("Not found\n");
                } else {
                    printf("Found\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}