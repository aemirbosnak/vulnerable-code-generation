//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to print out the status of the ship
void printShipStatus(int health, int fuel, int credits) {
    printf("Ship Status:\n");
    printf("Health: %d\n", health);
    printf("Fuel: %d\n", fuel);
    printf("Credits: %d\n", credits);
    printf("----------------------\n");
}

int main() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("----------------------\n");

    // Set initial game variables
    int health = 100;
    int fuel = 100;
    int credits = 0;

    printf("Your ship is ready for takeoff.\n");

    // Loop through game until player wins or loses
    while(health > 0) {
        int event = getRandomNumber(1, 3);

        // Event 1: Asteroid Field
        if(event == 1) {
            printf("You find yourself in an asteroid field!\n");
            int damage = getRandomNumber(10, 20);
            health -= damage;
            printf("You took %d damage from the asteroids.\n", damage);
            printShipStatus(health, fuel, credits);
        }
        // Event 2: Trade Station
        else if(event == 2) {
            printf("You come across a trade station!\n");
            int trade = getRandomNumber(1, 2);
            if(trade == 1) {
                int creditsGained = getRandomNumber(50, 100);
                printf("You sold some goods and gained %d credits.\n", creditsGained);
                credits += creditsGained;
                printShipStatus(health, fuel, credits);
            }
            else {
                int creditsSpent = getRandomNumber(50, 100);
                if(credits >= creditsSpent) {
                    printf("You bought some goods for %d credits.\n", creditsSpent);
                    credits -= creditsSpent;
                    printShipStatus(health, fuel, credits);
                }
                else {
                    printf("You don't have enough credits to buy anything!\n");
                    printShipStatus(health, fuel, credits);
                }
            }
        }
        // Event 3: Abandoned Planet
        else {
            printf("You landed on an abandoned planet!\n");
            int refuel = getRandomNumber(1, 2);
            if(refuel == 1) {
                int fuelGained = getRandomNumber(50, 100);
                printf("You found some fuel and gained %d units.\n", fuelGained);
                fuel += fuelGained;
                printShipStatus(health, fuel, credits);
            }
            else {
                printf("You didn't find any fuel on the planet.\n");
                printShipStatus(health, fuel, credits);
            }
        }

        // Check if player has lost the game
        if(health <= 0) {
            printf("Your ship was destroyed. Game over.\n");
            return 0;
        }

        // Ask player what they want to do
        printf("What do you want to do?\n");
        printf("1. Continue flying\n");
        printf("2. Exit game\n");

        int choice;
        scanf("%d", &choice);

        // Exit game if player chooses to
        if(choice == 2) {
            printf("Thanks for playing Procedural Space Adventure!\n");
            return 0;
        }

        // Subtract fuel for each event
        fuel -= 10;

        // Check if player has enough fuel to continue
        if(fuel <= 0) {
            printf("You ran out of fuel and crashed. Game over.\n");
            return 0;
        }
    }

    return 0;
}