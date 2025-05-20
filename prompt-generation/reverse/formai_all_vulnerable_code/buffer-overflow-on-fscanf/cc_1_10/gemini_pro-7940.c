//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for the binary search tree
struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

// Insert a word into the binary search tree
struct node *insert(struct node *root, char *word) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->word = strdup(word);
        root->count = 1;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (strcmp(word, root->word) < 0) {
        root->left = insert(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word);
    } else {
        root->count++;
    }

    return root;
}

// Print the words in the binary search tree in order
void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    print_inorder(root->left);
    printf("%s: %d\n", root->word, root->count);
    print_inorder(root->right);
}

// Free the memory allocated for the binary search tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->word);
    free(root);
}

int main() {
    // Create the binary search tree
    struct node *root = NULL;

    // Read the words from the file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        root = insert(root, word);
    }

    fclose(fp);

    // Print the words in the binary search tree in order
    print_inorder(root);

    // Free the memory allocated for the binary search tree
    free_tree(root);

    return EXIT_SUCCESS;
}