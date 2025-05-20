//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define global variables    
int health = 100;
int wealth = 100;
int food = 10;
int water = 10;

// Define function prototypes
void welcome();
void game();
void gameOver();
int randomInt(int min, int max);
void hunt();
void trade();
void rest();

int main() {
    welcome();
    game();
    return 0;
}

// Displays welcome message and game instructions
void welcome() {
    printf("Welcome to the Statistical Adventure Game!\n");
    printf("In this game, you will navigate through various scenarios\n");
    printf("with statistical outcomes. Your goal is to maximize your health\n");
    printf("and wealth by making careful decisions.\n\n");
    printf("You start the game with 100 health and 100 wealth, and 10 units\n");
    printf("of both food and water. Good luck!\n\n");
}

// Runs the main game loop
void game() {
    int gameOverFlag = 0; // Flag to indicate if game over condition has been met
    int day = 1; // Keep track of the number of days played

    while (!gameOverFlag) {
        printf("----- Day %d -----\n", day);
        printf("Health: %d\n", health);
        printf("Wealth: %d\n", wealth);
        printf("Food: %d\n", food);
        printf("Water: %d\n\n", water);

        // Display menu options
        printf("1. Hunt for food and water (50% chance of success)\n");
        printf("2. Trade with a merchant (80% chance of success)\n");
        printf("3. Rest up (20% chance of being attacked by bandits)\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                hunt();
                break;
            case 2:
                trade();
                break;
            case 3:
                rest();
                break;
            default:
                printf("Invalid option! Please try again.\n\n");
                continue;
        }

        // Update day and check for game over condition
        day++;
        if (health <= 0 || wealth <= 0 || food <= 0 || water <= 0) {
            gameOverFlag = 1;
        }
    }

    // Game is over, display final stats and end program
    gameOver();
}

// Displays game over message and final stats
void gameOver() {
    printf("Game over!\n");
    if (health <= 0) {
        printf("You died from a fatal injury.\n");
    } else if (wealth <= 0) {
        printf("You went bankrupt and could not afford basic necessities.\n");
    } else if (food <= 0 || water <= 0) {
        printf("You ran out of food and water and starved to death.\n");
    }
    printf("Final Health: %d\n", health);
    printf("Final Wealth: %d\n", wealth);
    printf("Final Food: %d\n", food);
    printf("Final Water: %d\n", water);
}

// Simulates a hunting activity
void hunt() {
    int successChance = randomInt(1, 100);
    if (successChance <= 50) {
        printf("You went hunting and successfully found food and water!\n\n");
        food += randomInt(1, 3);
        water += randomInt(1, 3);
    } else {
        printf("You went hunting, but could not find any food or water.\n\n");
    }

    // Reduce health due to hunting activity
    health -= randomInt(10, 20);
}

// Simulates a trading activity
void trade() {
    int successChance = randomInt(1, 100);
    if (successChance <= 80) {
        int tradeAmount = randomInt(10, 30);
        printf("You traded with a merchant and gained %d wealth!\n\n", tradeAmount);
        wealth += tradeAmount;
    } else {
        printf("You tried to trade with a merchant, but they were not interested.\n\n");
    }

    // Reduce food and water due to trading activity
    food--;
    water--;
}

// Simulates a resting activity
void rest() {
    int attackChance = randomInt(1, 100);
    if (attackChance <= 20) {
        printf("You were attacked by bandits while sleeping!\n\n");
        health -= randomInt(40, 60);
        wealth -= randomInt(20, 40);
    } else {
        printf("You rested peacefully and regained some health.\n\n");
        health += randomInt(10, 20);
    }

    // Reduce food and water due to resting activity
    food--;
    water--;
}

// Generates a random integer between min (inclusive) and max (inclusive)
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}