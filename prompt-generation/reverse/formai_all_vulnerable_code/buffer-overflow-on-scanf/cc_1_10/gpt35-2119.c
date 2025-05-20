//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// Define a function to create a new node
struct node *createNode(int key)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Define a function to insert a node into the tree
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Define a function to search for a key in the tree
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// Define a function to display the tree in order
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Define the main function
int main()
{
    struct node *root = NULL;
    int choice = 0;
    int key = 0;

    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display in order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
                printf("%d is found in the tree.\n", key);
            else
                printf("%d is not found in the tree.\n", key);
            break;
        case 3:
            printf("The tree in order is: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}