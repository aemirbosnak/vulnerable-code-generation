//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *newNode(int data) {
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node
struct node *search(struct node *root, int data) {
    if (root == NULL) {
        printf("Access Denied. Node not found.\n");
        return NULL;
    }
    if (data == root->data) {
        printf("Access Granted. Node found at location %p.\n", &root->data);
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Cyberpunk styled graphics
void cyberLogo() {
    printf("  ________   ________   ___  __           __   ________   _________ \n");
    printf(" /\"       ) /\"       ) |\"  ||\"$\\         /\"\"\\ /\"       ) /\"        \\\n");
    printf("(:   \\___/ (:   \\___/  ||  ||\\$$\\       /    (:   \\___/ (:   \\___/ \n");
    printf(" \\___  \\     \\___  \\   |:  || /  \\\\     /' /\\__\\___  \\   \\___  \\   \n");
    printf("  __/  \\\\     __/  \\\\  |.  ||/..\\ \\\\   //\\/ /\"\\__/  \\\\    __/  \\\\  \n");
    printf(" /\" \\   :)   /\" \\   :) |___|\\_______) (\\__//(___/  \\\\|  /\" \\   :) \n");
    printf("(___.\\_/   (___.\\_/  (_____/\\/_____/    \\________/(__/(___.\\_/   \n");

}

int main() {
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 8);
    insert(root, 7);
    insert(root, 15);
    insert(root, 20);
    insert(root, 17);

    cyberLogo();

    printf("WELCOME TO THE PUNKY BINARY SEARCH TREE INTEL\n\n");
    int choice;
    int value;
    do {
        printf("\n1- Search\n2- Quit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Thank you for choosing Punky Binary Search Tree Intel!");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    } while (choice != 2);
    return 0;
}