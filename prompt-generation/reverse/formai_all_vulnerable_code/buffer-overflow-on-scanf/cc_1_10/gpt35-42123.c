//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ship {
    char name[20];
    int health;
    int shield;
    int fuel;
    int ammo;
};

void printShipDetails(struct Ship ship) {
    printf("\n---------------------------------------\n");
    printf("Ship Name: %s\n", ship.name);
    printf("Health: %d\n", ship.health);
    printf("Shield: %d\n", ship.shield);
    printf("Fuel: %d\n", ship.fuel);
    printf("Ammo: %d\n", ship.ammo);
    printf("---------------------------------------\n");
}

int main() {
    struct Ship myShip = {"Cybership", 100, 50, 200, 200};

    printf("Welcome to the Cyberspace Adventure!\n");
    printf("You are the captain of the Cybership.\n");
    printf("Your mission is to explore the galaxy and find new planets for human colonization.\n");
    printf("Your journey to the stars will be full of challenges and dangers.\n");
    printf("Are you ready to start the adventure? (Y/N)\n");

    char answer[10];
    scanf("%s", answer);

    if (strcmp(answer, "Y") == 0) {
        printf("Great! Let's start the engines and lift off.\n");
        printf("We need to find a planet with suitable environment for human life.\n");
        printf("But beware of space pirates and other dangers lurking in the galaxy.\n");

        while (myShip.health > 0 && myShip.fuel > 0 && myShip.ammo > 0) {
            printShipDetails(myShip);

            printf("What would you like to do?\n");
            printf("1. Explore a new planet.\n");
            printf("2. Fight space pirates.\n");
            printf("3. Refuel the ship.\n");
            printf("4. Repair the ship.\n");
            printf("5. Quit the game.\n");

            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Scanning the nearby star systems for potential habitable planets...\n");
                    printf("We have found a planet with oxygen-rich atmosphere and moderate climate.\n");
                    printf("Landing on the planet...\n");
                    printf("Exploring the planet...\n");
                    printf("We have found some valuable resources that we can use to build new colonies.\n");
                    myShip.health -= 10;
                    myShip.fuel -= 20;
                    myShip.ammo -= 20;
                    break;
                case 2:
                    printf("Alert! Space pirates are attacking!\n");
                    printf("Preparing the ship's weapons...\n");
                    printf("Engaging the enemy...\n");
                    printf("We have won the battle, but our shield is damaged.\n");
                    myShip.health -= 20;
                    myShip.shield -= 10;
                    myShip.fuel -= 10;
                    myShip.ammo -= 30;
                    break;
                case 3:
                    printf("Refueling the ship...\n");
                    printf("The ship's fuel tank is now full.\n");
                    myShip.fuel = 200;
                    break;
                case 4:
                    printf("Repairing the ship...\n");
                    printf("The ship's health and shield are now fully restored.\n");
                    myShip.health = 100;
                    myShip.shield = 50;
                    break;
                case 5:
                    printf("Thanks for playing Cyberspace Adventure.\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }

            if (myShip.health <= 0) {
                printf("Game over! Your ship has been destroyed.\n");
                exit(0);
            }

            if (myShip.fuel <= 0) {
                printf("Game over! You have run out of fuel.\n");
                exit(0);
            }

            if (myShip.ammo <= 0) {
                printf("Game over! You have run out of ammo.\n");
                exit(0);
            }
        }

    } else {
        printf("Goodbye!\n");
    }

    return 0;
}