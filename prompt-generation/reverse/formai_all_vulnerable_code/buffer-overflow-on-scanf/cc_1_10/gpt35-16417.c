//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void navigation(int *shipX, int *shipY) {
    int choice;
    printf("Current coordinates: (%d,%d)\n", *shipX, *shipY);
    printf("Choose a direction to travel:\n1. North\n2. East\n3. South\n4. West\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            *shipY += 1;
            break;
        case 2:
            *shipX += 1;
            break;
        case 3:
            *shipY -= 1;
            break;
        case 4:
            *shipX -= 1;
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void encounter(int *shipX, int *shipY) {
    printf("You have encountered an alien spacecraft!\n");
    int outcome = rand() % 3;
    if (outcome == 0) {
        printf("The ship is friendly and offers to trade.\n");
        printf("What would you like to trade for?\n1. Fuel\n2. Provisions\n3. Upgrades\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You receive an extra gallon of fuel.\n");
                break;
            case 2:
                printf("You receive a box of rations for the crew.\n");
                break;
            case 3:
                printf("You receive a new laser weapon for the ship.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else if (outcome == 1) {
        printf("The ship opens fire on you!\n");
        printf("You take 20 damage to the hull.\n");
    } else {
        printf("The ship seems to be malfunctioning and drifts away.\n");
        printf("You gain 10 fuel from salvaging its wreckage.\n");
        *shipX += 1;
        *shipY -= 1;
    }
}

void gameLoop() {
    int shipX = 0;
    int shipY = 0;
    int fuel = 50;
    int hull = 100;
    int provisions = 10;
    printf("Welcome aboard the Galactic Explorer!\n");
    while (fuel > 0 && hull > 0 && provisions > 0) {
        int event = rand() % 10;
        if (event == 0) {
            printf("You find a deserted planet and scavenge for resources.\n");
            printf("You gain 20 fuel and 5 provisions.\n");
            fuel += 20;
            provisions += 5;
        } else if (event < 4) {
            encounter(&shipX, &shipY);
        } else {
            navigation(&shipX, &shipY);
            printf("You travel through the void of space...\n");
            fuel -= 5;
        }
        hull -= 5;
        provisions -= 1;
    }
    if (fuel == 0) {
        printf("You run out of fuel and are stranded in space. Game Over.\n");
    } else if (hull == 0) {
        printf("Your ship takes too much damage and explodes. Game Over.\n");
    } else if (provisions == 0) {
        printf("Your crew runs out of food and mutinies. Game Over.\n");
    } else {
        printf("Congratulations, you've completed your journey through the galaxy!\n");
        printf("Final coordinates: (%d,%d)\n", shipX, shipY);
    }
}

int main() {
    srand(time(NULL));
    gameLoop();
    return 0;
}