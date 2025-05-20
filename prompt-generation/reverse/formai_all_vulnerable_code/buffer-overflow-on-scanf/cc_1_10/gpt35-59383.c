//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Defining structure for planet data */
typedef struct {
    char name[20];
    int distanceFromSun;
    int numMoons;
} Planet;

/* Function to print planet information */
void printPlanetInfo(Planet *p) {
    printf("\n%s is located %d million miles from the sun and has %d moons.\n", p->name, p->distanceFromSun, p->numMoons);
}

int main() {
    /* Initializing planets */
    Planet mercury = {"Mercury", 36, 0};
    Planet venus = {"Venus", 67, 0};
    Planet earth = {"Earth", 93, 1};
    Planet mars = {"Mars", 142, 2};
    Planet jupiter = {"Jupiter", 484, 79};
    Planet saturn = {"Saturn", 886, 82};
    Planet uranus = {"Uranus", 1782, 27};
    Planet neptune = {"Neptune", 2793, 14};
    Planet pluto = {"Pluto", 3670, 5};

    /* Initializing spaceship properties */
    int fuelLevel = 100;
    int distanceTraveled = 0;

    /* Initializing game variables */
    int gameOver = 0;
    int planetVisited = 0;

    /* Starting the game */
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship and need to visit all the planets in the solar system.\n");
    printf("Your spaceship has enough fuel to travel 100 million miles on a full tank.\n");
    printf("You can refuel at any planet for 50 million dollars per unit.\n");
    printf("Get ready to launch!\n");

    /* Game loop */
    while (!gameOver) {
        printf("\n\nYou are currently %d million miles from the sun.\n", distanceTraveled);

        /* Checking if spaceship has enough fuel to travel to next planet */
        if (distanceTraveled + 100 > pluto.distanceFromSun) {
            printf("Congrats! You have visited all the planets!\n");
            gameOver = 1;
            break;
        }

        /* Checking if spaceship has enough fuel to travel to next planet */
        if (fuelLevel < 10) {
            printf("Warning: Fuel level is critically low. You need to refuel!\n");
        } else {
            printf("Select a planet to visit:\n");
        }
        printf("1. Mercury\n");
        printf("2. Venus\n");
        printf("3. Earth\n");
        printf("4. Mars\n");
        printf("5. Jupiter\n");
        printf("6. Saturn\n");
        printf("7. Uranus\n");
        printf("8. Neptune\n");
        printf("9. Pluto\n");

        /* Getting user input */
        int input;
        scanf("%d", &input);

        /* Checking if user input is valid */
        if (input < 1 || input > 9) {
            printf("Invalid input! Please select again.\n");
            continue;
        }

        /* Traveling to selected planet */
        switch (input) {
            case 1:
                fuelLevel -= (mercury.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = mercury.distanceFromSun;
                printPlanetInfo(&mercury);
                break;
            case 2:
                fuelLevel -= (venus.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = venus.distanceFromSun;
                printPlanetInfo(&venus);
                break;
            case 3:
                fuelLevel -= (earth.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = earth.distanceFromSun;
                printPlanetInfo(&earth);
                break;
            case 4:
                fuelLevel -= (mars.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = mars.distanceFromSun;
                printPlanetInfo(&mars);
                break;
            case 5:
                fuelLevel -= (jupiter.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = jupiter.distanceFromSun;
                printPlanetInfo(&jupiter);
                break;
            case 6:
                fuelLevel -= (saturn.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = saturn.distanceFromSun;
                printPlanetInfo(&saturn);
                break;
            case 7:
                fuelLevel -= (uranus.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = uranus.distanceFromSun;
                printPlanetInfo(&uranus);
                break;
            case 8:
                fuelLevel -= (neptune.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = neptune.distanceFromSun;
                printPlanetInfo(&neptune);
                break;
            case 9:
                fuelLevel -= (pluto.distanceFromSun - distanceTraveled) / 10;
                distanceTraveled = pluto.distanceFromSun;
                printPlanetInfo(&pluto);
                break;
        }

        /* Checking if spaceship has enough fuel for return journey */
        if (fuelLevel < (distanceTraveled / 2)) {
            printf("Warning: You do not have enough fuel to make the return journey back to earth!\n");
            printf("Game over!\n");
            gameOver = 1;
            break;
        }

        /* Checking if planet has already been visited */
        if (!planetVisited) {
            printf("Do you want to refuel at this planet?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            /* Getting user input */
            scanf("%d", &input);

            /* Refueling spaceship */
            if (input == 1) {
                printf("You have refueled your spaceship for 50 million dollars.\n");
                fuelLevel = 100;
            }

            /* Marking planet visited */
            planetVisited = 1;
        }

        /* Displaying fuel level */
        printf("Your fuel level is %d.\n", fuelLevel);
    }

    return 0;
}