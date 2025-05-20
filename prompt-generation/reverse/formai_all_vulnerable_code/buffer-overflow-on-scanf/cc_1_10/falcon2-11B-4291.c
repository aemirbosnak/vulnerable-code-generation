//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>

// Node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return newNode(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to search a node
int search(struct Node* root, int data)
{
    if (root == NULL)
        return 0;
    else if (data < root->data)
        return search(root->left, data);
    else if (data > root->data)
        return search(root->right, data);
    else
        return 1;
}

// Function to print the tree
void print(struct Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
}

// Main function
int main()
{
    struct Node* root = NULL;
    int choice, data;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &choice);
    printf("\nEnter the data for each node:\n");
    for (int i = 0; i < choice; i++)
    {
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nThe binary search tree is:\n");
    print(root);

    printf("\nEnter the data to be searched: ");
    scanf("%d", &data);
    if (search(root, data))
        printf("%d is present in the tree\n", data);
    else
        printf("%d is not present in the tree\n", data);

    return 0;
}