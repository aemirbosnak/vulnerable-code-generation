//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure
typedef struct node {
    char word[MAX_SIZE];
    int count;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a word into the tree
Node* insert(Node* root, char* word) {
    if (root == NULL) {
        root = createNode(word);
    } else if (strcmp(root->word, word) == 0) {
        root->count++;
    } else if (strcmp(root->word, word) > 0) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }

    return root;
}

// Function to search for a word in the tree
Node* search(Node* root, char* word) {
    if (root == NULL || strcmp(root->word, word) == 0) {
        return root;
    } else if (strcmp(root->word, word) > 0) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

// Function to print the tree in alphabetical order
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);

    printf("%s (%d)\n", root->word, root->count);

    printTree(root->right);
}

// Function to delete a word from the tree
Node* deleteWord(Node* root, char* word) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(root->word, word) == 0) {
        if (root->count == 1) {
            free(root);
            return NULL;
        } else {
            root->count--;
        }
    } else if (strcmp(root->word, word) > 0) {
        root->left = deleteWord(root->left, word);
    } else {
        root->right = deleteWord(root->right, word);
    }

    return root;
}

// Main function
int main() {
    Node* root = NULL;
    char word[MAX_SIZE];

    printf("Enter words to insert into the tree:\n");
    while (scanf("%s", word) == 1) {
        root = insert(root, word);
    }

    printf("\nWords in alphabetical order:\n");
    printTree(root);

    printf("\n\nEnter a word to search for:\n");
    scanf("%s", word);
    Node* found = search(root, word);

    if (found == NULL) {
        printf("Word not found.\n");
    } else {
        printf("Found '%s' with count %d.\n", found->word, found->count);
    }

    printf("\n\nEnter a word to delete:\n");
    scanf("%s", word);
    root = deleteWord(root, word);

    printf("\nWords in alphabetical order after deletion:\n");
    printTree(root);

    return 0;
}