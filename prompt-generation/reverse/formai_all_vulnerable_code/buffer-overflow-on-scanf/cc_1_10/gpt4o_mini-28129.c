//GPT-4o-mini DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TREES 10
#define MAX_GARDEN_SIZE 20

typedef struct {
    int x;
    int y;
    char name[20];
} Tree;

void initTrees(Tree garden[], int size) {
    const char *tree_names[] = {"Cedar", "Oak", "Pine", "Maple", "Birch", "Spruce", "Willow", "Peach", "Apple", "Cherry"};
    
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        garden[i].x = rand() % MAX_GARDEN_SIZE;
        garden[i].y = rand() % MAX_GARDEN_SIZE;
        strcpy(garden[i].name, tree_names[rand() % 10]);
    }
}

void displayGarden(Tree garden[], int size) {
    char grid[MAX_GARDEN_SIZE][MAX_GARDEN_SIZE] = {{'.'}};

    for (int i = 0; i < size; i++) {
        grid[garden[i].y][garden[i].x] = 'T';
    }

    printf("Your Peaceful Garden:\n");
    for (int y = 0; y < MAX_GARDEN_SIZE; y++) {
        for (int x = 0; x < MAX_GARDEN_SIZE; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

void plantNewTree(Tree garden[], int *size) {
    if (*size >= MAX_TREES) {
        printf("The garden is full! You cannot plant more trees.\n");
        return;
    }
    
    printf("Enter the tree name you want to plant: ");
    char tree_name[20];
    scanf("%s", tree_name);
    
    garden[*size].x = rand() % MAX_GARDEN_SIZE;
    garden[*size].y = rand() % MAX_GARDEN_SIZE;
    strcpy(garden[*size].name, tree_name);
    
    (*size)++;
    printf("Successfully planted a %s tree in your garden!\n", tree_name);
}

void listTrees(Tree garden[], int size) {
    printf("Current Trees in your Garden:\n");
    for (int i = 0; i < size; i++) {
        printf("%s tree at position (%d, %d)\n", garden[i].name, garden[i].x, garden[i].y);
    }
}

void relaxInTheGarden() {
    printf("You sit down on a cozy bench and enjoy the sunny day surrounded by beautiful trees.\n");
    printf("What a lovely garden you have!\n");
    
    // Simulate relaxation time for a few seconds
    for (int i = 0; i < 5; i++) {
        printf("Taking a moment to breathe...\n");
        sleep(1);
    }
}

int main() {
    Tree garden[MAX_TREES];
    int treeCount = 0;
    int choice;

    initTrees(garden, 5); // Initialize with 5 random trees

    do {
        printf("\nWelcome to Your Peaceful Garden!\n");
        printf("1. Display Garden\n");
        printf("2. Plant a New Tree\n");
        printf("3. List Current Trees\n");
        printf("4. Relax in the Garden\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayGarden(garden, treeCount);
                break;
            case 2:
                plantNewTree(garden, &treeCount);
                break;
            case 3:
                listTrees(garden, treeCount);
                break;
            case 4:
                relaxInTheGarden();
                break;
            case 5:
                printf("Exiting the garden. Have a peaceful day!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}