//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePlanet(int);
void visitPlanet(int *);
void talkToAlien(int);
void fightAlien(int *);

int main() {
    srand(time(NULL));
    int planet[10] = {0}, currentPlanet = 0;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are currently on planet %d.\n", currentPlanet + 1);
    printf("Let's explore the galaxy!\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Generate a new planet.\n");
        printf("2. Visit a nearby planet.\n");
        printf("3. Talk to an alien.\n");
        printf("4. Fight an alien.\n");
        printf("5. Quit the game.\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generatePlanet(currentPlanet);
                break;
            case 2:
                visitPlanet(&currentPlanet);
                break;
            case 3:
                talkToAlien(currentPlanet);
                break;
            case 4:
                fightAlien(&planet[currentPlanet]);
                break;
            case 5:
                printf("\nThanks for playing Procedural Space Adventure!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void generatePlanet(int planetNum) {
    printf("\nGenerating a new planet...\n");
    printf("Planet %d has been successfully generated!\n\n", planetNum + 2);
}

void visitPlanet(int *currentPlanet) {
    if (*currentPlanet == 9) {
        printf("\nYou have visited all the planets in the galaxy!\n");
        printf("Congratulations! You have completed Procedural Space Adventure!\n");
        exit(0);
    } else {
        *currentPlanet += 1;
        printf("\nYou have successfully visited planet %d!\n", *currentPlanet + 1);
    }
}

void talkToAlien(int planetNum) {
    printf("\nYou are talking to an alien on planet %d.\n", planetNum + 1);
    printf("The alien says hello!\n\n");
}

void fightAlien(int *planet) {
    if (*planet == 1) {
        printf("\nYou have successfully defeated the alien on this planet!\n");
        *planet = 0;
    } else {
        printf("\nThere are no aliens on this planet!\n");
    }
}