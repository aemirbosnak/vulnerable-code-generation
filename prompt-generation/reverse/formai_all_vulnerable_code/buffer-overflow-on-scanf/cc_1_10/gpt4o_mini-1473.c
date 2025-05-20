//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcome() {
    printf("Welcome to Happy Farm Adventure!\n");
    printf("Here, you'll grow your own crops and collect happiness points!\n");
    printf("Are you ready to create a beautiful farm of joy? Let's go!\n\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. You have a fixed amount of space to plant crops.\n");
    printf("2. Choose which crop to plant each turn.\n");
    printf("3. Earn happiness points by growing and harvesting crops.\n");
    printf("4. Try to achieve the highest happiness points!\n\n");
}

void printStatus(int happinessPoints, int cropsPlanted, int days) {
    printf("---------------------------------------------------\n");
    printf("Day %d\n", days);
    printf("Happiness Points: %d\n", happinessPoints);
    printf("Crops Planted: %d\n", cropsPlanted);
    printf("---------------------------------------------------\n");
}

int main() {
    srand(time(0));
    
    int happinessPoints = 0;
    int cropsPlanted = 0;
    int maxCrops = 10;
    int days = 1;
    int choice;

    printWelcome();
    printInstructions();

    while (days <= 30) {
        printStatus(happinessPoints, cropsPlanted, days);
    
        printf("Choose a crop to plant (1: Carrot, 2: Potato, 3: Tomato, 4: Harvest, 5: Quit): ");
        scanf("%d", &choice);
    
        if (choice == 1) {
            printf("You planted a Carrot! It will grow in 3 days.\n");
            cropsPlanted++;
            happinessPoints += 3;
        } else if (choice == 2) {
            printf("You planted a Potato! It will grow in 4 days.\n");
            cropsPlanted++;
            happinessPoints += 4;
        } else if (choice == 3) {
            printf("You planted a Tomato! It will grow in 5 days.\n");
            cropsPlanted++;
            happinessPoints += 5;
        } else if (choice == 4) {
            if (cropsPlanted > 0) {
                printf("Harvesting crops...\n");
                int harvestPoints = (rand() % 5) + 1; // Random points between 1 and 5
                happinessPoints += harvestPoints;
                cropsPlanted--;
                printf("You harvested crops and gained %d happiness points!\n", harvestPoints);
            } else {
                printf("You have no crops to harvest!\n");
            }
        } else if (choice == 5) {
            printf("Thank you for playing! You finished with %d happiness points!\n", happinessPoints);
            break;
        } else {
            printf("Invalid choice, please select again.\n");
        }

        printf("\n--- Day %d has ended! ---\n\n", days);
        days++;
    }

    if (days > 30) {
        printf("The month is over! Your final happiness points total is: %d\n", happinessPoints);
    }
    
    return 0;
}