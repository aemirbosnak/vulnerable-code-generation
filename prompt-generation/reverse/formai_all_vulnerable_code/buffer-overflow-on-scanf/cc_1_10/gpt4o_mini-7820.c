//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FLOWERS 10

typedef struct {
    char name[20];
    int health;
    int water;
    int fertilizer;
} Flower;

void simulateDay(Flower *flower) {
    flower->health -= (rand() % 3); // Random decrease in health
    if (flower->water > 0) {
        flower->water--;
        flower->health += 1; // Health improves with water
    }
    if (flower->fertilizer > 0) {
        flower->fertilizer--;
        flower->health += 2; // Health improves with fertilizer
    }
    // Ensure health does not go below 0
    if (flower->health < 0) {
        flower->health = 0;
    }
}

void plantFlower(Flower *garden, int *flowerCount) {
    if (*flowerCount >= MAX_FLOWERS) {
        printf("Your garden is full! You can't plant more flowers.\n");
        return;
    }
    
    Flower newFlower;
    printf("Enter the name of the flower: ");
    scanf("%s", newFlower.name);
    newFlower.health = 5; // Starting health
    newFlower.water = 0;   // No water initially
    newFlower.fertilizer = 0; // No fertilizer initially
    
    garden[*flowerCount] = newFlower;
    (*flowerCount)++;
    printf("You have planted a %s flower!\n", newFlower.name);
}

void waterFlower(Flower *garden, int flowerCount) {
    char flowerName[20];
    printf("Enter the name of the flower to water: ");
    scanf("%s", flowerName);
    
    for (int i = 0; i < flowerCount; i++) {
        if (strcmp(garden[i].name, flowerName) == 0) {
            garden[i].water++;
            printf("You watered the %s flower!\n", garden[i].name);
            return;
        }
    }
    printf("No flower with the name '%s' found in your garden.\n", flowerName);
}

void fertilizeFlower(Flower *garden, int flowerCount) {
    char flowerName[20];
    printf("Enter the name of the flower to fertilize: ");
    scanf("%s", flowerName);
    
    for (int i = 0; i < flowerCount; i++) {
        if (strcmp(garden[i].name, flowerName) == 0) {
            garden[i].fertilizer++;
            printf("You fertilized the %s flower!\n", garden[i].name);
            return;
        }
    }
    printf("No flower with the name '%s' found in your garden.\n", flowerName);
}

void displayGarden(Flower *garden, int flowerCount) {
    if (flowerCount == 0) {
        printf("Your garden is empty.\n");
        return;
    }
    
    printf("Your garden:\n");
    for (int i = 0; i < flowerCount; i++) {
        printf("Flower: %s, Health: %d, Water: %d, Fertilizer: %d\n",
                garden[i].name, garden[i].health, garden[i].water, garden[i].fertilizer);
    }
}

int main() {
    srand(time(NULL));
    Flower garden[MAX_FLOWERS];
    int flowerCount = 0;
    int day = 1;
    char command[20];

    printf("Welcome to the Garden Keeper Game!\n\n");
    
    while (1) {
        printf("\n--- Day %d ---\n", day);
        displayGarden(garden, flowerCount);
        
        printf("What would you like to do? (plant, water, fertilize, next, quit): ");
        scanf("%s", command);
        
        if (strcmp(command, "plant") == 0) {
            plantFlower(garden, &flowerCount);
        } else if (strcmp(command, "water") == 0) {
            waterFlower(garden, flowerCount);
        } else if (strcmp(command, "fertilize") == 0) {
            fertilizeFlower(garden, flowerCount);
        } else if (strcmp(command, "next") == 0) {
            for (int i = 0; i < flowerCount; i++) {
                simulateDay(&garden[i]);
            }
            day++;
        } else if (strcmp(command, "quit") == 0) {
            printf("Thank you for playing! Your garden will stay as it is.\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    
    return 0;
}