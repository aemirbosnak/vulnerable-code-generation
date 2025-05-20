//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct tnode {
    char word[MAX_WORD_LENGTH];
    struct tnode* left;
    struct tnode* right;
} TNode;

TNode* create_node(char* word) {
    TNode* new_node = (TNode*) malloc(sizeof(TNode));
    strcpy(new_node->word, word);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TNode* insert_node(TNode* root, char* word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert_node(root->right, word);
    } else if (strcmp(root->word, word) > 0) {
        root->left = insert_node(root->left, word);
    }

    return root;
}

void inorder_traversal(TNode* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%s ", root->word);
    inorder_traversal(root->right);
}

int main() {
    TNode* root = NULL;

    root = insert_node(root, "apple");
    root = insert_node(root, "banana");
    root = insert_node(root, "orange");
    root = insert_node(root, "grape");
    root = insert_node(root, "pear");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}