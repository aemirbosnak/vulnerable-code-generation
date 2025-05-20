//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>


// Let's get our roots in order
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// It's time to make a new Node. Like a trendy tree parent!
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Oops! Out of memory! Can't create more nodes, will start losing leaves...\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Let's put this node where it belongs like a good librarian
Node* insert(Node* root, int data) {
    if (root == NULL) {
        // Let's plant a new tree!
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Duplicate value! Node %d already exists in our tree. No selfies allowed!\n", data);
    }
    return root;
}

// Pre-order traversal: Let's get this tree looking good for a photo
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// In-order traversal: Because even trees love order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Post-order traversal: Cleaning up after ourselves, like good citizens
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Searching for value in our beloved tree
Node* search(Node* root, int data) {
    if (root == NULL) {
        printf("Value %d not found. Such a bummer!\n", data);
        return NULL;
    }
    if (root->data == data) {
        printf("Found %d! It's been hiding in the branches!\n", data);
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } 
    return search(root->right, data);
}

// Deleting a node: When we have tree-rrible news
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        printf("Nothing to delete, tree is still happy!\n");
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        printf("Deleting node %d...\n", data);
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Let's unleash our tree on the world with some creativity!
int main() {
    Node* root = NULL;
    int choice, value;

    printf("Welcome to the Wacky Binary Search Tree! 🌳 Let's plant some fun!\n");

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Pre-order Traversal\n5. In-order Traversal\n6. Post-order Traversal\n7. Exit\n");
        printf("Choose your adventure (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d! 🎉\n", value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 4:
                printf("Pre-order Traversal:\n");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("In-order Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order Traversal:\n");
                postOrder(root);
                printf("\n");
                break;
            case 7:
                printf("Thanks for playing with the tree! 🌳❤️ Bye!\n");
                break;
            default:
                printf("Oops! Invalid choice! 🤪\n");
                break;
        }

    } while (choice != 7);

    // Freeing the allocated memory, because we care for the environment!
    printf("Freeing all the nodes. It's time for nature to reclaim its land! 🌍\n");
    // Add code for freeing nodes here if needed

    return 0;
}