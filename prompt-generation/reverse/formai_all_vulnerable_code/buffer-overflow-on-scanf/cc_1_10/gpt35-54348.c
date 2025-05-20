//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main(void) {
    int score = 0;
    int distance = 100000;
    int fuel = 100;
    int choice;
    srand(time(0));

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of the Space Ship, The Millenium Mallard.\n");
    printf("Your mission is to visit the planets and collect rare items for the Intergalactic Museum.\n");
    printf("Be careful, there are many obstacles in the way and you have limited fuel!\n");

    while (distance > 0 && fuel > 0) {
        printf("\nCurrent Distance to the Target: %d\n", distance);
        printf("Current Fuel Level: %d\n", fuel);

        printf("1. Fly Forward.\n");
        printf("2. Stop to Collect Items.\n");
        printf("3. Stop to Refuel.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            distance -= (rand()%5000 + 10000);
            fuel -= rand()%10 + 1;
            score += rand()%100 + 1;
            printf("Flying Forward...\n");
            delay(2);
            printf("You traveled %d units.\n", (rand()%5000 + 10000));
            printf("You collected %d rare items!\n", (rand()%10 + 1));
            printf("You used %d units of fuel.\n", (rand()%10 + 1));
        } else if (choice == 2) {
            score += rand()%500 + 1;
            printf("Stopping to Collect Items...\n");
            delay(2);
            printf("You found %d rare items!\n", (rand()%500 + 1));
            printf("You gained %d points!\n", (rand()%500 + 1));
        } else if (choice == 3) {
            fuel = 100;
            printf("Stopping to Refuel...\n");
            delay(2);
            printf("Fuel Level Restored to 100 units!\n");
        } else {
            printf("Invalid Choice!\n");
            continue;
        }
    }

    if (distance <= 0) {
        printf("\nCongratulations! You have reached the target and collected enough items for the Museum!\n");
        printf("Your Final Score: %d\n", score);
    } else {
        printf("\nYour Space Ship has run out of fuel and is lost in space...\n");
        printf("Your Final Score: %d\n", score);
    }

    return 0;
}