//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initializeGame();
void printIntro();
int playGame();
void printEnding(int score);

// game variables
int score = 0;
int radiation = 50;
int shields = 100;
int fuel = 100;
int distance = 0;

// main function
int main() {
    initializeGame();
    printIntro();
    int result = playGame();
    printEnding(result);
    return 0;
}

// function to initialize game variables
void initializeGame() {
    srand(time(NULL));
    radiation = rand() % 50 + 50;
    shields = rand() % 50 + 50;
    fuel = rand() % 50 + 50;
}

// function to print game introduction
void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of the spaceship Odyssey.\n");
    printf("Your mission is to explore the galaxy and reach the edge of the universe.\n");
    printf("But be careful, there are many dangers out there, such as radiation storms, asteroid fields, and enemy ships.\n");
    printf("You start with 100% shields, 100% fuel, and 0% radiation.\n");
}

// function to play the game
int playGame() {
    while (distance < 100) {
        printf("\nCurrent Status:\n");
        printf("Distance Traveled: %d light years\n", distance);
        printf("Radiation: %d%%\n", radiation);
        printf("Shields: %d%%\n", shields);
        printf("Fuel: %d%%\n", fuel);
        printf("What do you want to do?\n");
        printf("1. Travel to a new destination\n");
        printf("2. Activate the shields\n");
        printf("3. Refuel the ship\n");
        printf("4. Check the map\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Traveling to a new destination...\n");
                int radiationChange = rand() % 10 + 1;
                int shieldsChange = rand() % 10 + 1;
                int fuelChange = rand() % 10 + 1;
                radiation += radiationChange;
                shields -= shieldsChange;
                fuel -= fuelChange;
                distance += 10;
                printf("Radiation + %d%%\n", radiationChange);
                printf("Shields - %d%%\n", shieldsChange);
                printf("Fuel - %d%%\n", fuelChange);
                score += 10;
                break;
            case 2:
                printf("Activating shields...\n");
                int shieldRecharge = rand() % 10 + 1;
                shields += shieldRecharge;
                radiation -= 10;
                printf("Shields + %d%%\n", shieldRecharge);
                printf("Radiation - 10%%\n");
                score += 5;
                break;
            case 3:
                printf("Refueling the ship...\n");
                int fuelRefill = rand() % 10 + 1;
                fuel += fuelRefill;
                radiation -= 5;
                printf("Fuel + %d%%\n", fuelRefill);
                printf("Radiation - 5%%\n");
                score += 5;
                break;
            case 4:
                printf("Checking the map...\n");
                score -= 5;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // check for game over conditions
        if (radiation >= 100 || shields <= 0 || fuel <= 0) {
            return 0;
        }
    }
    return 1;
}

// function to print game ending
void printEnding(int result) {
    if (result == 0) {
        printf("\nGAME OVER\n");
        printf("Your ship has been destroyed. You failed the mission.\n");
    } else {
        printf("\nCONGRATULATIONS!\n");
        printf("You have successfully reached the edge of the universe!\n");
    }
    printf("Final Score: %d\n", score);
}