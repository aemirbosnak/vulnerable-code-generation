//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data)
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

struct node *search_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data == root->data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search_node(root->left, data);
    }
    else
    {
        return search_node(root->right, data);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, data;
    char ch;

    do
    {
        printf("\n1. Insert a node\n");
        printf("2. Search a node\n");
        printf("3. Inorder traversal\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            root = insert_node(root, data);
            break;

        case 2:
            printf("\nEnter the data to be searched: ");
            scanf("%d", &data);
            struct node *found_node = search_node(root, data);
            if (found_node == NULL)
            {
                printf("\nNode not found\n");
            }
            else
            {
                printf("\nNode found: %d\n", found_node->data);
            }
            break;

        case 3:
            printf("\nInorder traversal: ");
            inorder_traversal(root);
            printf("\n");
            break;

        case 4:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}