//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int main() {
    struct node *root = NULL;
    int data;
    char choice;
    
    printf("My dearest love, let us create a beautiful binary tree together.\n");
    printf("With each node, we shall inscribe a memory, a cherished moment we hold dear.\n");
    
    while (1) {
        printf("\nMy love, what memory would you like to add to our tree? (Enter an integer or 'q' to quit): ");
        scanf("%d", &data);
        
        if (data == 'q') {
            break;
        }
        
        root = insert_node(root, data);
        
        printf("My heart flutters with joy as I place this memory in our tree. It shall forever be etched in our love's embrace.\n");
    }
    
    printf("\nMy darling, our tree of memories is complete. Let us search for a moment that holds special significance for us.\n");
    printf("Enter the memory you wish to find (or 'q' to quit): ");
    scanf("%d", &data);
    
    while (data != 'q') {
        struct node *found_node = search_node(root, data);
        
        if (found_node == NULL) {
            printf("My dearest, I cannot find that memory in our tree. Perhaps it was a fleeting thought, or a dream that has yet to come true.\n");
        } else {
            printf("My heart leaps with joy! I have found the memory you seek. It is a precious gem in our love's treasury.\n");
        }
        
        printf("\nEnter another memory you wish to find (or 'q' to quit): ");
        scanf("%d", &data);
    }
    
    printf("\nMy love, our time together has been a cherished memory I shall hold in my heart forever.\n");
    printf("May our binary tree of memories continue to grow and flourish, an eternal testament to our love's unbreakable bond.\n");
    
    return 0;
}