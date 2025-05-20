//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 1000
#define MAX_FUEL 100
#define PLANET_X 500
#define PLANET_Y 500

void travel(int fuel, int* current_distance, int* x_coordinate, int* y_coordinate);
void refuel(int* fuel);

int main() {
    int fuel = MAX_FUEL;
    int current_distance = 0;
    int x_coordinate = 0;
    int y_coordinate = 0;

    //random seed for generating planets
    srand(time(NULL));

    printf("Welcome to your space adventure!\n");
    printf("You start at (0, 0) and must reach the planet at (%d, %d).\n", PLANET_X, PLANET_Y);

    while(current_distance < MAX_DISTANCE) {
        printf("You are currently at (%d, %d).\n", x_coordinate, y_coordinate);
        printf("You have %d fuel.\n", fuel);

        int choice;
        printf("What would you like to do?\n");
        printf("1. Travel to a new location.\n");
        printf("2. Refuel for 10 fuel.\n");
        printf("3. Quit the game.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                travel(fuel, &current_distance, &x_coordinate, &y_coordinate);
                break;
            case 2:
                refuel(&fuel);
                break;
            case 3:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }

        //generate a new planet if the player has travelled at least 50 units
        if(current_distance >= 50) {
            int x = rand() % MAX_DISTANCE;
            int y = rand() % MAX_DISTANCE;

            printf("You have discovered a new planet at (%d, %d)!\n", x, y);
        }
    }

    printf("Congratulations, you have reached the planet!\n");
    printf("Thanks for playing!\n");

    return 0;
}

void travel(int fuel, int* current_distance, int* x_coordinate, int* y_coordinate) {
    if(fuel == 0) {
        printf("You have no fuel left, please refuel.\n");
        return;
    }

    int x, y;
    printf("Enter the x-coordinate of your destination: ");
    scanf("%d", &x);
    printf("Enter the y-coordinate of your destination: ");
    scanf("%d", &y);

    int distance = abs(*x_coordinate - x) + abs(*y_coordinate - y);

    if(distance > fuel) {
        printf("You do not have enough fuel to travel that far.\n");
        return;
    }

    *current_distance += distance;
    *x_coordinate = x;
    *y_coordinate = y;
    fuel -= distance;

    printf("You have successfully travelled %d units to (%d, %d)!\n", distance, x, y);
}

void refuel(int* fuel) {
    *fuel += 10;
    printf("You have refueled 10 fuel units.\n");
}