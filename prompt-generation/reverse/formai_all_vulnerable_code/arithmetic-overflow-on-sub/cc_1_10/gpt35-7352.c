//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Position;

void printCoordinates(Position pos) {
    printf("(%d, %d)\n", pos.x, pos.y);
}

int main() {
    int choice;
    int fuel = 100;
    Position position = {0, 0};
    printf("Welcome to the peaceful space adventure!\n");
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Check current coordinates\n");
        printf("2. Refuel spaceship\n");
        printf("3. Travel to different coordinates\n");
        printf("4. Exit program\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Current Coordinates: ");
                printCoordinates(position);
                break;
            case 2:
                printf("Refueling spaceship...\n");
                fuel = 100;
                printf("Spaceship refueled!\n");
                break;
            case 3:
                if(fuel <= 0) {
                    printf("You do not have enough fuel to travel!\n");
                    break;
                }
                int newX, newY;
                printf("Enter the coordinates you would like to travel to (x y): ");
                scanf("%d %d", &newX, &newY);
                printf("Traveling to Coordinates: (%d, %d)\n", newX, newY);
                int xDist = abs(newX - position.x);
                int yDist = abs(newY - position.y);
                fuel -= xDist + yDist;
                if(fuel < 0) {
                    printf("You have run out of fuel and cannot travel further!\n");
                    fuel = 0;
                    break;
                }
                printf("Fuel Remaining: %d\n", fuel);
                position.x = newX;
                position.y = newY;
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    return 0;
}