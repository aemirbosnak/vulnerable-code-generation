//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a binary search tree (BST)
struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

// Insert a word into a BST
struct node *insert(struct node *root, char *word) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->word = strdup(word);
        root->count = 1;
        root->left = root->right = NULL;
    } else if (strcmp(word, root->word) < 0) {
        root->left = insert(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word);
    } else {
        root->count++;
    }
    return root;
}

// Count the number of words in a file
int count_words(FILE *fp) {
    int count = 0;
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        count++;
    }
    return count;
}

// Print the words in a BST in alphabetical order
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%s: %d\n", root->word, root->count);
    print_tree(root->right);
}

// Free the memory allocated for a BST
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
    // Open the file to be processed
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count the number of words in the file
    int num_words = count_words(fp);

    // Create a BST to store the words
    struct node *root = NULL;
    for (int i = 0; i < num_words; i++) {
        char word[100];
        fscanf(fp, "%s", word);
        root = insert(root, word);
    }

    // Print the words in the BST in alphabetical order
    print_tree(root);

    // Free the memory allocated for the BST
    free_tree(root);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}