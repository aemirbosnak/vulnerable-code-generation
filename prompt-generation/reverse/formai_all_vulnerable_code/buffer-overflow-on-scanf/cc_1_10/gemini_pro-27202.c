//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main()
{
    node *root = NULL;
    int data;
    printf("Enter the data for the binary search tree (-1 to exit): ");
    while (scanf("%d", &data) != EOF && data != -1)
    {
        root = insert_node(root, data);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n");
    return 0;
}