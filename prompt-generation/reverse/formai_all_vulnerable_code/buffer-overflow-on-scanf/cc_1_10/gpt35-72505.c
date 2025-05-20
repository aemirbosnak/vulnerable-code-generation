//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>

// Function declaration
void searchPlanet(int planetNum);

int main() {
    printf("Welcome to the Procedural Space Adventure!\n\n");
    printf("You have been sent on a mission to explore a new solar system.\n");
    printf("You have a map that displays the planets in the system.\n\n");

    int choice;
    printf("Which planet would you like to explore first? Enter 1-5: ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 5) {
        printf("Invalid choice. Please enter a number between 1 and 5: ");
        scanf("%d", &choice);
    }

    searchPlanet(choice);

    return 0;
}

// Function definition
void searchPlanet(int planetNum) {
    char planetName[15];
    int numMoons;
    float distance;
    int alienEncounter;

    switch (planetNum) {
        case 1:
            sprintf(planetName, "Alpha");
            numMoons = 2;
            distance = 500.25;
            alienEncounter = 1;
            break;

        case 2:
            sprintf(planetName, "Beta");
            numMoons = 1;
            distance = 430.78;
            alienEncounter = 0;
            break;

        case 3:
            sprintf(planetName, "Gamma");
            numMoons = 4;
            distance = 620.50;
            alienEncounter = 1;
            break;

        case 4:
            sprintf(planetName, "Delta");
            numMoons = 0;
            distance = 800.90;
            alienEncounter = 0;
            break;

        case 5:
            sprintf(planetName, "Epsilon");
            numMoons = 3;
            distance = 950.30;
            alienEncounter = 0;
            break;
    }

    printf("\n\nYou have reached Planet %d (%s)!\n", planetNum, planetName);
    printf("It is %f million kilometers away and has %d moons.\n\n", distance, numMoons);

    if (alienEncounter) {
        printf("Oh no! You have encountered a group of hostile aliens!\n");
        printf("You must defend yourself with your space blaster!\n\n");
    } else {
        printf("It seems there is no sign of any life on this planet.\n");
        printf("You explore the planet and find some interesting rock formations.\n\n");
    }
}