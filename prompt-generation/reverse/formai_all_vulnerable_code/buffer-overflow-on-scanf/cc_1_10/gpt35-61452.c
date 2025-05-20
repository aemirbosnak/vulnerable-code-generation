//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *newNode(int data)
{
    Node *new = (Node *) malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(Node **tree, int data)
{
    if (*tree == NULL)
        *tree = newNode(data);
    else if (data <= (*tree)->data)
        insert(&(*tree)->left, data);
    else
        insert(&(*tree)->right, data);
}

void inorder(Node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

int search(Node *tree, int data)
{
    if (tree == NULL)
        return 0;
    else if (tree->data == data)
        return 1;
    else if (data <= tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

int main()
{
    Node *tree = NULL;
    int n, data, elem, i;
    printf("Enter the number of elements to insert into BST:\n");
    scanf("%d", &n);
    printf("Enter the elements to be inserted:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(&tree, data);
    }
    printf("Inorder traversal of the BST:\n");
    inorder(tree);
    printf("\nEnter the element to be searched:\n");
    scanf("%d", &elem);
    if (search(tree, elem) == 1)
        printf("%d exists in the BST.\n", elem);
    else
        printf("%d does not exist in the BST.\n", elem);
    return 0;
}