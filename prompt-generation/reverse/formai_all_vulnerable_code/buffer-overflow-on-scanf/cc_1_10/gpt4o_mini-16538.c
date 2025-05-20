//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flower {
    char name[30];
    char color[20];
    int growthStage; // 0: Seed, 1: Bud, 2: Bloom, 3: Wither
    struct Flower* next;
} Flower;

Flower* gardenHead = NULL;

// Function to create a new flower
Flower* createFlower(const char* name, const char* color, int growthStage) {
    Flower* newFlower = (Flower*)malloc(sizeof(Flower));
    if (!newFlower) {
        printf("Oh no! Unable to plant that flower! Memory issues...\n");
        return NULL;
    }
    strncpy(newFlower->name, name, sizeof(newFlower->name) - 1);
    strncpy(newFlower->color, color, sizeof(newFlower->color) - 1);
    newFlower->growthStage = growthStage;
    newFlower->next = NULL;
    return newFlower;
}

// Function to plant a flower in the memory garden
void plantFlower(const char* name, const char* color, int growthStage) {
    Flower* newFlower = createFlower(name, color, growthStage);
    if (newFlower != NULL) {
        newFlower->next = gardenHead;
        gardenHead = newFlower;
        printf("A beautiful %s flower named %s has been planted!\n", color, name);
    }
}

// Function to display the flowers in the garden
void viewGarden() {
    printf("\n🌸 Welcome to the Memory Garden 🌸\n");
    printf("Here are the flowers currently in bloom:\n");
    Flower* current = gardenHead;
    int count = 0;
    
    while (current) {
        printf(" - %s (%s) - Stage: %d\n", current->name, current->color, current->growthStage);
        current = current->next;
        count++;
    }
    
    if (count == 0) {
        printf("The garden is empty... Plant some flowers!\n");
    }
}

// Function to uproot (free) a flower
void uprootFlower(const char* name) {
    Flower* current = gardenHead;
    Flower* prev = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Alas! A flower named '%s' was not found in the garden.\n", name);
        return;
    }
    
    if (prev == NULL) { // Flower is the head
        gardenHead = current->next;
    } else {
        prev->next = current->next;
    }
    
    printf("The flower %s has been uprooted from the memory garden!\n", current->name);
    free(current);
}

// Function to free all flowers in the garden
void freeGarden() {
    Flower* current = gardenHead;
    Flower* nextFlower;
    
    while (current != NULL) {
        nextFlower = current->next;
        printf("Freeing flower %s...\n", current->name);
        free(current);
        current = nextFlower;
    }
    
    gardenHead = NULL;
}

int main() {
    int choice;
    char name[30], color[20];
    int growthStage;

    do {
        printf("\n🔧 Memory Garden Menu 🔧\n");
        printf("1. Plant a flower\n");
        printf("2. View the garden\n");
        printf("3. Uproot a flower\n");
        printf("4. Exit and free memory\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter flower name: ");
                scanf("%s", name);
                printf("Enter flower color: ");
                scanf("%s", color);
                printf("Enter growth stage (0-3): ");
                scanf("%d", &growthStage);
                plantFlower(name, color, growthStage);
                break;
            case 2:
                viewGarden();
                break;
            case 3:
                printf("Enter the name of the flower to uproot: ");
                scanf("%s", name);
                uprootFlower(name);
                break;
            case 4:
                printf("Exiting... Freeing the Memory Garden...\n");
                freeGarden();
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}