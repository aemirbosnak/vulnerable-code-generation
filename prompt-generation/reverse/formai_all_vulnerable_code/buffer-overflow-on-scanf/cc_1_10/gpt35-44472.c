//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void inorder(struct node* node)
{
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

struct node* search(struct node* node, int data)
{
    if (node == NULL || node->data == data)
        return node;

    if (node->data < data)
        return search(node->right, data);

    return search(node->left, data);
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    int searchKey;
    printf("\nEnter a number to search in the binary search tree: ");
    scanf("%d", &searchKey);
    struct node* searchedNode = search(root, searchKey);
    if(searchedNode != NULL)
        printf("The number %d is present in the binary search tree.", searchKey);
    else
        printf("The number %d is not present in the binary search tree.", searchKey);

    return 0;
}