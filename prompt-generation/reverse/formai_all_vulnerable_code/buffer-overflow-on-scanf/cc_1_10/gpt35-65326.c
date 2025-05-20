//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE* create_node(int data) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

NODE* insert(NODE *root, int data) {
    if(root == NULL){
        root = create_node(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

NODE* search(NODE *root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    } else if(data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    NODE *root = NULL;
    int choice,data;
    while (1) {
        printf("1. Insert\n2. Search\n3. Quit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d",&data);
                if(search(root, data) == NULL) {
                    printf("Element not found!\n");
                } else {
                    printf("Element found!\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}