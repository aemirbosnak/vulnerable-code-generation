//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>

/* function prototypes */
void explorePlanet(int planetNum);
void navigateShip(char direction);

/* main function */
int main() {

    printf("Welcome to Procedural Space Adventure!\n");

    int choice;

    printf("Which planet would you like to explore?\n");
    printf("1. Planet X\n");
    printf("2. Planet Y\n");
    printf("3. Planet Z\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            explorePlanet(1);
            break;
        case 2:
            explorePlanet(2);
            break;
        case 3:
            explorePlanet(3);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            break;
    }

    printf("Thanks for playing Procedural Space Adventure!\n");

    return 0;
}

/* function implementations */
void explorePlanet(int planetNum) {
    printf("Exploring Planet %d...\n", planetNum);
    printf("What direction would you like to navigate your ship?\n");
    printf("N for North, S for South, E for East, W for West.\n");

    char direction;
    scanf(" %c", &direction);

    navigateShip(direction);

    printf("Exiting planet %d.\n", planetNum);
}

void navigateShip(char direction) {
    printf("Navigating ship %c.\n", direction);
}