//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREES 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int health; // From 0 (dead) to 100 (very healthy)
} Tree;

typedef struct {
    Tree trees[MAX_TREES];
    int count;
} Forest;

// Function declarations
void addTree(Forest *forest);
void listTrees(const Forest *forest);
void removeTree(Forest *forest);
void updateTreeHealth(Tree *tree);
void displayMenu();

int main() {
    Forest magicalForest = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTree(&magicalForest);
                break;
            case 2:
                listTrees(&magicalForest);
                break;
            case 3:
                removeTree(&magicalForest);
                break;
            case 4:
                printf("Thank you for visiting the magical forest. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Magical Forest Management System ---\n");
    printf("1. Add a tree\n");
    printf("2. List all trees\n");
    printf("3. Remove a tree\n");
    printf("4. Exit\n");
}

void addTree(Forest *forest) {
    if (forest->count >= MAX_TREES) {
        printf("The forest is full! Can't add more trees.\n");
        return;
    }

    Tree newTree;
    printf("Enter tree name: ");
    scanf("%s", newTree.name);
    newTree.health = rand() % 101; // Random health between 0 and 100

    forest->trees[forest->count++] = newTree;
    printf("Tree '%s' added with health %d!\n", newTree.name, newTree.health);
}

void listTrees(const Forest *forest) {
    if (forest->count == 0) {
        printf("There are no trees in the forest!\n");
        return;
    }

    printf("\n--- List of Trees in the Magical Forest ---\n");
    for (int i = 0; i < forest->count; i++) {
        const Tree *tree = &forest->trees[i];
        printf("Tree %d: Name: %s, Health: %d\n", i + 1, tree->name, tree->health);
    }
}

void removeTree(Forest *forest) {
    if (forest->count == 0) {
        printf("There are no trees to remove!\n");
        return;
    }

    int index;
    printf("Enter the number of the tree to remove (1 - %d): ", forest->count);
    scanf("%d", &index);

    if (index < 1 || index > forest->count) {
        printf("Invalid tree number!\n");
        return;
    }

    // Shift trees to remove the selected one
    for (int i = index - 1; i < forest->count - 1; i++) {
        forest->trees[i] = forest->trees[i + 1];
    }
    forest->count--;

    printf("Tree number %d has been removed from the forest!\n", index);
}

void updateTreeHealth(Tree *tree) {
    int change = (rand() % 21) - 10; // Change health by -10 to +10
    tree->health += change;

    if (tree->health > 100) tree->health = 100;
    if (tree->health < 0) tree->health = 0;
}