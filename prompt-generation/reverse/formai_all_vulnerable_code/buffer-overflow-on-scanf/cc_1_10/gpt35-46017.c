//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Coordinates;

void flyTo(Coordinates coords) {
    printf("Drone is flying to coordinates: (%d, %d)\n", coords.x, coords.y);
}

void hover() {
    printf("Drone is hovering\n");
}

void land() {
    printf("Drone is landing\n");
}

void takeOff() {
    printf("Drone is taking off\n");
}

int main() {
    int choice;
    Coordinates destination;

    printf("Welcome to the drone remote control program!\n");
    printf("1. Take off\n");
    printf("2. Fly to a location\n");
    printf("3. Hover in place\n");
    printf("4. Land\n");
    printf("5. Quit\n");

    while (1) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeOff();
                break;
            case 2:
                printf("Enter the x-coordinate: ");
                scanf("%d", &destination.x);
                printf("Enter the y-coordinate: ");
                scanf("%d", &destination.y);
                flyTo(destination);
                break;
            case 3:
                hover();
                break;
            case 4:
                land();
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }

        printf("\n");
    }

    return 0;
}