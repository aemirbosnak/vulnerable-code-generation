//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FLOWERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int growth;
    int watered;
    time_t lastWatered;
} Flower;

Flower garden[MAX_FLOWERS];
int flowerCount = 0;

void addFlower() {
    if (flowerCount >= MAX_FLOWERS) {
        printf("Your garden is full! Cannot add more flowers.\n");
        return;
    }

    Flower newFlower;
    printf("Enter the name of the flower: ");
    scanf("%s", newFlower.name);
    newFlower.growth = 0;
    newFlower.watered = 0;
    newFlower.lastWatered = time(NULL);

    garden[flowerCount] = newFlower;
    flowerCount++;
    printf("You have planted a %s!\n", newFlower.name);
}

void waterFlower() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the flower you want to water: ");
    scanf("%s", name);

    for (int i = 0; i < flowerCount; i++) {
        if (strcmp(garden[i].name, name) == 0) {
            garden[i].watered = 1;
            garden[i].lastWatered = time(NULL);
            printf("You watered the %s!\n", garden[i].name);
            return;
        }
    }
    printf("No flower with the name %s in your garden.\n", name);
}

void growFlowers() {
    for (int i = 0; i < flowerCount; i++) {
        if (garden[i].watered) {
            garden[i].growth++;
            if (garden[i].growth >= 5) {
                printf("The %s has blossomed beautifully!\n", garden[i].name);
            }
        }
        garden[i].watered = 0; // Reset after growing
    }
}

void showGarden() {
    if (flowerCount == 0) {
        printf("Your garden is empty. Plant some flowers first!\n");
        return;
    }

    printf("\n--- Your Garden ---\n");
    for (int i = 0; i < flowerCount; i++) {
        printf("%s: Growth Level: %d | Last Watered: %s", garden[i].name, garden[i].growth, ctime(&garden[i].lastWatered));
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("Welcome to the Virtual Garden!\n");
        printf("1. Plant a Flower\n");
        printf("2. Water a Flower\n");
        printf("3. Show Garden\n");
        printf("4. Grow Flowers\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFlower();
                break;
            case 2:
                waterFlower();
                break;
            case 3:
                showGarden();
                break;
            case 4:
                growFlowers();
                break;
            case 5:
                printf("Thank you for visiting the Virtual Garden. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}