//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void start();
void navigate();
void explore();
void encounter();
void gameOver();

// global variables
int distance = 0;
int resource = 100;

int main() {
    srand(time(NULL)); // seed the random number generator
    start();
    return 0;
}

void start() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are the captain of a spaceship and your mission is to explore the galaxy.\n");
    printf("You will encounter various alien species and must navigate through asteroid fields.\n");
    printf("You start with 100 resource points and must manage them wisely.\n\n");

    navigate();
}

void navigate() {
    printf("You are currently %d light years away from Earth.\n", distance);

    int choice;
    printf("What would you like to do?\n");
    printf("1. Travel to a new star system\n");
    printf("2. Explore your current location\n");
    printf("3. View ship status\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            distance += (rand() % 11) + 10; // travel 10-20 light years
            printf("You have traveled %d light years.\n\n", distance);
            explore();
            break;
        case 2:
            explore();
            break;
        case 3:
            printf("Ship Status\n");
            printf("Distance from Earth: %d light years\n", distance);
            printf("Resource Points: %d\n\n", resource);
            navigate();
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
            navigate();
            break;
    }
}

void explore() {
    printf("You are now exploring the galaxy.\n");

    int encounterChance = rand() % 101; // 0-100

    if (encounterChance <= 30) { // 30% chance of an encounter
        encounter();
    } else {
        printf("You did not encounter any alien species or asteroid fields.\n\n");
        navigate();
    }
}

void encounter() {
    int encounterType = rand() % 2; // 0-1

    if (encounterType == 0) {
        printf("You have encountered an alien species!\n");

        int alienAttack = (rand() % 11) + 5; // 5-15 resource points
        int playerAttack = (rand() % 16) + 5; // 5-20 resource points

        printf("Your ship attacked for %d resource points.\n", playerAttack);
        printf("The alien species attacked for %d resource points.\n\n", alienAttack);

        resource -= alienAttack;
        if (resource <= 0) {
            gameOver();
        } else {
            printf("You successfully defeated the alien species and gained 10 resource points.\n\n");
            resource += 10;
            navigate();
        }
    } else {
        printf("You have encountered an asteroid field!\n");

        int resourceLost = (rand() % 21) + 5; // 5-25 resource points
        resource -= resourceLost;

        if (resource <= 0) {
            gameOver();
        } else {
            printf("You successfully navigated through the asteroid field but lost %d resource points.\n\n", resourceLost);
            navigate();
        }
    }
}

void gameOver() {
    printf("Game over. You have run out of resource points and your ship has been destroyed.\n");
    exit(0);
}