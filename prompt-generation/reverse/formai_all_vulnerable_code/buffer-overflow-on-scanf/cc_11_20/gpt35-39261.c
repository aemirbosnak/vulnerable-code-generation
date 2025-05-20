//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Procedural Space Adventure!\n\n");

    // Variables for the spaceship
    int fuel = 50, hull = 100, distance = 0;

    // Variables for the planets
    int mercury = 36, venus = 67, earth = 93, mars = 142, jupiter = 484, saturn = 886, uranus = 1782, neptune = 2793, pluto = 3674;

    // Ask user where they want to go
    printf("Where do you want to go?\n");
    printf("1) Mercury\n2) Venus\n3) Earth\n4) Mars\n5) Jupiter\n6) Saturn\n7) Uranus\n8) Neptune\n9) Pluto\n");
    int choice;
    scanf("%d", &choice);

    // Calculate distance and fuel cost
    if (choice == 1) {
        distance = mercury;
        fuel -= 3;
    }
    else if (choice == 2) {
        distance = venus;
        fuel -= 5;
    }
    else if (choice == 3) {
        distance = earth;
        fuel -= 7;
    }
    else if (choice == 4) {
        distance = mars;
        fuel -= 8;
    }
    else if (choice == 5) {
        distance = jupiter;
        fuel -= 20;
    }
    else if (choice == 6) {
        distance = saturn;
        fuel -= 25;
    }
    else if (choice == 7) {
        distance = uranus;
        fuel -= 30;
    }
    else if (choice == 8) {
        distance = neptune;
        fuel -= 35;
    }
    else if (choice == 9) {
        distance = pluto;
        fuel -= 40;
    }
    else {
        printf("Invalid choice, defaulting to Earth\n");
        distance = earth;
    }

    // Check fuel and update distance
    if (fuel < 0) {
        printf("The spaceship ran out of fuel and is now stranded in space!\n");
        return 0;
    }
    else {
        printf("The spaceship traveled %d million kilometers to its destination!\n", distance);
    }

    // Calculate hull damage
    if (distance > 500) {
        hull -= 10;
    }
    else if (distance > 1000) {
        hull -= 20;
    }
    else if (distance > 2000) {
        hull -= 30;
    }
    else {
        hull -= 5;
    }

    // Check hull integrity
    if (hull <= 0) {
        printf("The spaceship was destroyed due to hull damage and the crew was lost.\n");
        return 0;
    }

    // Generate random event
    int event = rand() % 3;
    if (event == 0) {
        printf("Space debris damaged the spaceship's hull!\n");
        hull -= 10;
    }
    else if (event == 1) {
        printf("The spaceship encountered a friendly alien race who replenished the fuel!\n");
        fuel += 10;
    }
    else {
        printf("The spaceship encountered hostile alien spacecrafts!\n");
        int enemy_ships = rand() % 5;
        hull -= enemy_ships * 10;
    }

    // Final report
    printf("The spaceship's fuel level is now %d and its hull integrity is %d.\n", fuel, hull);

    return 0;
}