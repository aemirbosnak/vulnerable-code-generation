//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

typedef struct CreatureNode {
    char name[NAME_LENGTH];
    struct CreatureNode *left;
    struct CreatureNode *right;
} CreatureNode;

CreatureNode* createNode(const char* name) {
    CreatureNode* newNode = (CreatureNode*)malloc(sizeof(CreatureNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

CreatureNode* insertCreature(CreatureNode* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertCreature(root->left, name);
    } else {
        root->right = insertCreature(root->right, name);
    }
    return root;
}

void printTree(CreatureNode* root, int space) {
    if (root == NULL) return;

    space += 10;  // Increase distance between levels

    printTree(root->right, space);
    printf("\n");
    
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%s\n", root->name);

    printTree(root->left, space);
}

void freeTree(CreatureNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    CreatureNode* forest = NULL;
    char name[NAME_LENGTH];
    char choice;

    printf("Welcome to the Mystical Forest!\n");
    printf("Here you can create your own magical creature tree.\n");

    do {
        printf("Enter the name of a creature to add to the forest: ");
        scanf("%s", name);
        forest = insertCreature(forest, name);

        printf("Do you want to add another creature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nHere's the structure of your mystical forest:\n");
    printTree(forest, 0);

    freeTree(forest);
    printf("Thank you for visiting the Mystical Forest!\n");

    return 0;
}