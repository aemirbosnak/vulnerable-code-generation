//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Module for spaceship functionalities */
void spaceship_module() {
    printf("Welcome to your spaceship!\n");
    printf("What do you want to do?\n");
    printf("1. Travel to a different planet\n");
    printf("2. Refuel the spaceship\n");
    printf("3. Check the spaceship's status\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("You have successfully travelled to a different planet!\n");
            break;
        case 2:
            printf("The spaceship has been refueled!\n");
            break;
        case 3:
            printf("The spaceship's status is normal.\n");
            break;
        default:
            printf("Invalid input!\n");
    }
}

/* Module for alien interactions */
void alien_module() {
    printf("You have encountered some aliens!\n");
    printf("What do you want to do?\n");
    printf("1. Communicate with the aliens\n");
    printf("2. Attack the aliens\n");
    printf("3. Flee\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("You have successfully communicated with the aliens!\n");
            break;
        case 2:
            printf("You have successfully defeated the aliens!\n");
            break;
        case 3:
            printf("You have successfully fled from the aliens!\n");
            break;
        default:
            printf("Invalid input!");
    }
}

/* Main program */
int main() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("What do you want to do first?\n");
    printf("1. Explore the galaxy\n");
    printf("2. Upgrade your spaceship\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            spaceship_module();
            alien_module();
            printf("Thanks for playing!\n");
            break;
        case 2:
            printf("You have successfully upgraded your spaceship!\n");
            spaceship_module();
            alien_module();
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid input!\n");
    }
    return 0;
}