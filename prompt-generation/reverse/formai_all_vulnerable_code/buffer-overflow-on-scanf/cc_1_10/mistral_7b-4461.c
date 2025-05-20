//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_HEIGHT 10
#define SPACES_PER_LEVEL 5

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void printTree(TreeNode *root, int level) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    for (int i = 0; i < level * SPACES_PER_LEVEL; i++) {
        putchar(' ');
    }

    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

void generateRandomTree(TreeNode **root, int height) {
    if (*root != NULL) {
        return;
    }

    *root = malloc(sizeof(TreeNode));
    (*root)->data = rand() % (2 * height) - height;
    (*root)->left = NULL;
    (*root)->right = NULL;

    if (height > 1) {
        generateRandomTree(&((*root)->left), height - 1);
        generateRandomTree(&((*root)->right), height - 1);
    }
}

int main() {
    TreeNode *root = NULL;
    int height;

    if (scanf("%d", &height) != 1 || height <= 0 || height > MAX_HEIGHT) {
        printf("Invalid height.\n");
        return 1;
    }

    generateRandomTree(&root, height);

    printf("Tree with %d levels:\n", height);
    printTree(root, 0);

    return 0;
}